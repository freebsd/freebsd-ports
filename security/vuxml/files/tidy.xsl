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
  doctype-system="http://www.vuxml.org/dtd/vuxml-1/vuxml-11.dtd"
  doctype-public="-//vuxml.org//DTD VuXML 1.1//EN"
  indent="yes"
  />

<!--
All this special care is needed so that we can control the
output of namespace declarations.  Using copy/copy-of may
result in more namespace declarations than we wish.
-->

<xsl:template match="/">
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
  <xsl:element name="{name()}">
    <xsl:attribute
      name="xmlns">http://www.vuxml.org/apps/vuxml-1</xsl:attribute>
    <xsl:for-each select="@*">
      <xsl:attribute name="{name()}"><xsl:value-of
	select="." /></xsl:attribute>
    </xsl:for-each>
    <xsl:for-each select="vuxml:vuln">
      <xsl:sort
	order="descending"
	select="vuxml:dates/*[last()]/text()" />
      <xsl:text disable-output-escaping="yes">&#10;&#32;&#32;</xsl:text>
      <xsl:apply-templates select="." />
      <xsl:text disable-output-escaping="yes">&#10;</xsl:text>
    </xsl:for-each>
  </xsl:element>
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
  </xsl:call-template>
</xsl:template>


<!-- Include a namespace declaration on the <body> element. -->
<xsl:template match="xhtml:body">
  <xsl:element name="{name()}">
    <xsl:attribute
      name="xmlns">http://www.w3.org/1999/xhtml</xsl:attribute>
    <xsl:call-template name="copy-attr">
      <xsl:with-param name="node" select="." />
    </xsl:call-template>
    <xsl:apply-templates />
  </xsl:element>
</xsl:template>

<!-- Default copy. -->
<xsl:template match="*">
  <xsl:element name="{name()}">
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
  <xsl:element name="{name($node)}">
    <xsl:call-template name="copy-attr">
      <xsl:with-param name="node" select="$node" />
    </xsl:call-template>
    <xsl:value-of select="normalize-space($node/text())" />
  </xsl:element>
</xsl:template>

</xsl:stylesheet>
