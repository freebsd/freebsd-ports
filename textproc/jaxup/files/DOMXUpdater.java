/**
 * DOMXUpdater: a command-line XUpdate processor.
 * 
 * $FreeBSD$
 */
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;

import org.apache.xml.serialize.OutputFormat;
import org.apache.xml.serialize.XMLSerializer;
import org.jaxen.dom.DocumentNavigator;
import org.jaxup.dom.DOMDocumentUpdater;
import org.jaxup.xupdate.XUpdate;
import org.w3c.dom.Document;

public class DOMXUpdater
{
	public static void main(String[] args)
	{
		if (args.length != 2)
		{
			System.out.println("usage: DOMXUpdater <source document url> <XUpdate document url>");
			System.exit(1);
		}

		try
		{
			DocumentBuilderFactory factory=DocumentBuilderFactory.newInstance();
			factory.setNamespaceAware(true);
			DocumentBuilder builder=factory.newDocumentBuilder();

			Document doc=builder.parse(args[0]);
			Document updateDoc=builder.parse(args[1]);

			XUpdate updater=new XUpdate(new DOMDocumentUpdater(), DocumentNavigator.getInstance());
			updater.runUpdate(doc, updateDoc.getDocumentElement());

			OutputFormat o=new OutputFormat("xml", "ISO-8859-1", true);
			o.setIndenting(true);
			o.setIndent(2);
			o.setPreserveSpace(true);
			XMLSerializer serial=new XMLSerializer(System.out, o);
			serial.serialize(doc);
			System.out.println();
		}
		catch (Exception e)
		{
			e.printStackTrace();
			System.exit(1);
		}
	}
}
