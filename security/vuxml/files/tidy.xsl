<?xml version="1.0"?>
<xsl:stylesheet version="1.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
	xmlns:vuxml="http://www.vuxml.org/apps/vuxml-1"
	xmlns:xhtml="http://www.w3.org/1999/xhtml"
	exclude-result-prefixes="vuxml xhtml"
	>

<xsl:param name="upper" select="'ABCDEF'" />
<xsl:param name="lower" select="'abcdef'" />

<xsl:output
  method="xml"
  encoding="utf-8"
  omit-xml-declaration="yes"
  indent="yes"
  />

<!--
All this special care is needed so that we can control the
output of namespace declarations.  Using copy/copy-of may
result in more namespace declarations than we wish.
-->

<xsl:template match="/">
	<xsl:text disable-output-escaping="yes"><![CDATA[<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE vuxml PUBLIC "-//vuxml.org//DTD VuXML 1.1//EN" "http://www.vuxml.org/dtd/vuxml-1/vuxml-11.dtd" [
<!ENTITY vuln-2003 SYSTEM "vuln-2003.xml">
<!ENTITY vuln-2004 SYSTEM "vuln-2004.xml">
<!ENTITY vuln-2005 SYSTEM "vuln-2005.xml">
<!ENTITY vuln-2006 SYSTEM "vuln-2006.xml">
<!ENTITY vuln-2007 SYSTEM "vuln-2007.xml">
<!ENTITY vuln-2008 SYSTEM "vuln-2008.xml">
<!ENTITY vuln-2009 SYSTEM "vuln-2009.xml">
<!ENTITY vuln-2010 SYSTEM "vuln-2010.xml">
<!ENTITY vuln-2011 SYSTEM "vuln-2011.xml">
<!ENTITY vuln-2012 SYSTEM "vuln-2012.xml">
<!ENTITY vuln-2013 SYSTEM "vuln-2013.xml">
<!ENTITY vuln-2014 SYSTEM "vuln-2014.xml">
<!ENTITY vuln-2015 SYSTEM "vuln-2015.xml">
<!ENTITY vuln-2016 SYSTEM "vuln-2016.xml">
<!ENTITY vuln-2017 SYSTEM "vuln-2017.xml">
<!ENTITY vuln-2018 SYSTEM "vuln-2018.xml">
<!ENTITY vuln-2019 SYSTEM "vuln-2019.xml">
<!ENTITY vuln-2020 SYSTEM "vuln-2020.xml">
]>
]]></xsl:text>
  <xsl:apply-templates />
</xsl:template>

<!-- Copy processing instructions and comments, too. -->
<xsl:template match="processing-instruction()|comment()">
  <xsl:copy>
    <xsl:apply-templates />
  </xsl:copy>
</xsl:template>

<!--
Set the namespace on the <vuxml> element.  Sort the <vuln> elements
in descending order of their <modified> elements (or <entry>, if they
don't have <modified>).  Insert an empty line between <vuln> elements.
-->
<xsl:template match="vuxml:vuxml">
  <xsl:element name="{name()}" namespace="{namespace-uri(.)}">
    <xsl:for-each select="@*">
      <xsl:attribute name="{name()}"><xsl:value-of
	select="." /></xsl:attribute>
    </xsl:for-each>
    <xsl:for-each select="vuxml:vuln">
      <xsl:sort
	order="descending"
	select="vuxml:dates/entry/text()" />
      <xsl:text disable-output-escaping="yes">&#10;&#32;&#32;</xsl:text>
      <xsl:apply-templates select="." />
      <xsl:text disable-output-escaping="yes">&#10;</xsl:text>
    </xsl:for-each>
  </xsl:element>
<xsl:text>&#10;</xsl:text>
</xsl:template>

<!--
Many elements have only text content.  Strip extraneous whitespace
from those elements.
-->
<xsl:template match="vuxml:topic|vuxml:name|vuxml:le|vuxml:lt|
  vuxml:ge|vuxml:gt|vuxml:eq|vuxml:cvename|vuxml:url|vuxml:bid|
  vuxml:certsa|vuxml:certvu|vuxml:uscertsa|vuxml:uscertta|
  vuxml:mlist|vuxml:freebsdsa|vuxml:freebsdpr|vuxml:discovery|
  vuxml:entry|vuxml:modified">
  <xsl:call-template name="normalize-space">
    <xsl:with-param name="node" select="." />
    <xsl:with-param name="namespace" select="namespace-uri(.)" />
  </xsl:call-template>
</xsl:template>

<!-- Default copy. -->
<xsl:template match="*">
  <xsl:element name="{name()}" namespace="{namespace-uri(.)}">
    <xsl:call-template name="copy-attr">
      <xsl:with-param name="node" select="." />
    </xsl:call-template>
    <xsl:apply-templates />
  </xsl:element>
</xsl:template>

<!-- Copy attributes, but fold VuXML IDs (vid) to lower case.  -->
<xsl:template name="copy-attr">
  <xsl:param name="node" />
    <xsl:if test="$node/@vid">
      <xsl:attribute name="vid"><xsl:value-of
	  select="translate(@vid,$upper,$lower)" /></xsl:attribute>
    </xsl:if>
    <xsl:for-each select="$node/@*[name() != 'vid']">
      <xsl:attribute name="{name()}"><xsl:value-of
	select="." /></xsl:attribute>
    </xsl:for-each>
</xsl:template>

<!-- Strip whitespace from elements with only text -->
<xsl:template name="normalize-space">
  <xsl:param name="node" />
  <xsl:param name="namespace" />
  <xsl:element name="{name($node)}" namespace="{$namespace}">
    <xsl:call-template name="copy-attr">
      <xsl:with-param name="node" select="$node" />
    </xsl:call-template>
    <xsl:value-of select="normalize-space($node/text())" />
  </xsl:element>
</xsl:template>

</xsl:stylesheet>
