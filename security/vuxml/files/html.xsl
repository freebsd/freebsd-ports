<?xml version="1.0"?>
<!-- $FreeBSD$ -->
<xsl:stylesheet
  version="1.0"
  xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
  xmlns:vuxml="http://www.vuxml.org/apps/vuxml-1"
  xmlns:xhtml="http://www.w3.org/1999/xhtml"
  xmlns:exsl="http://exslt.org/common"
  extension-element-prefixes="exsl"
  exclude-result-prefixes="xhtml vuxml">

  <xsl:output method="xml" encoding="utf-8" indent="yes"
    doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd"
    doctype-public="-//W3C//DTD XHTML 1.0 Transitional//EN"/>

  <xsl:param name="vid" select="'none'" />

  <xsl:template match="/">
    <xsl:apply-templates select="vuxml:vuxml/vuxml:vuln[@vid = $vid]" />
  </xsl:template>

  <xsl:template name="range-spec">
    <xsl:param name="gt" />
    <xsl:param name="ge" />
    <xsl:param name="lt" />
    <xsl:param name="le" />
    <xsl:param name="eq" />
    <xsl:param name="name" />

    <tr valign="top">
      <td class="version">
	<xsl:choose>
	  <xsl:when test="$gt != ''"><xsl:value-of select="$gt" /></xsl:when>
	  <xsl:when test="$ge != ''"><xsl:value-of select="$ge" /></xsl:when>
	  <xsl:when test="$eq != ''"><xsl:value-of select="$eq" /></xsl:when>
	</xsl:choose>
      </td>
      <td class="operator">
	<xsl:choose>
	  <xsl:when test="$gt != ''">&#60;</xsl:when>
	  <xsl:when test="$ge != ''">&#60;&#61;</xsl:when>
	  <xsl:when test="$eq != ''">&#61;</xsl:when>
	</xsl:choose>
      </td>
      <td class="package"><xsl:element name="a">
	  <xsl:attribute name="href">
	    <xsl:value-of select="concat('pkg-', $name, '.html')" />
	  </xsl:attribute>
	  <xsl:value-of select="$name" /></xsl:element></td>
      <td class="operator">
	<xsl:choose>
	  <xsl:when test="$lt != ''">&#60;</xsl:when>
	  <xsl:when test="$le != ''">&#60;&#61;</xsl:when>
	</xsl:choose>
      </td>
      <td class="version">
	<xsl:choose>
	  <xsl:when test="$lt != ''"><xsl:value-of select="$lt" /></xsl:when>
	  <xsl:when test="$le != ''"><xsl:value-of select="$le" /></xsl:when>
	</xsl:choose>
      </td>
    </tr>
  </xsl:template>

  <xsl:template name="vuln-range">
    <xsl:param name="range" />
    <xsl:param name="name" />

    <xsl:for-each select="exsl:node-set($range)">
      <xsl:call-template name="range-spec">
	<xsl:with-param name="lt" select="vuxml:lt" />
	<xsl:with-param name="le" select="vuxml:le" />
	<xsl:with-param name="gt" select="vuxml:gt" />
	<xsl:with-param name="ge" select="vuxml:ge" />
	<xsl:with-param name="name" select="$name" />
      </xsl:call-template>
    </xsl:for-each>
  </xsl:template>

  <xsl:template name="stats" xmlns="http://www.w3.org/1999/xhtml">
    <xsl:param name="id" />
    <xsl:param name="label" />
    <xsl:param name="content" />

    <tr valign="top">
      <td class="label"><xsl:value-of select="$label" /></td>
      <td class="content">
	<xsl:element name="span">
	  <xsl:attribute name="class"><xsl:value-of select="$id" /></xsl:attribute>
	  <xsl:value-of select="$content" /></xsl:element>
      </td>
    </tr>
  </xsl:template>

  <xsl:template match="vuxml:vuln">
    <html xmlns="http://www.w3.org/1999/xhtml">
      <head>
	<title><xsl:value-of select="vuxml:topic" /></title>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8;" />
	<link rel="stylesheet" type="text/css" href="common.css" />
      </head>

      <body>
	<h1 class="title"><xsl:value-of select="vuxml:topic" /></h1>

	<table cellspacing="12">
	  <tr valign="top">
	    <td><table class="list">
		<thead><tr><td colspan="5">Affected packages</td></tr></thead>
		<tbody>
		  <xsl:for-each select="vuxml:affects/vuxml:package">
		    <xsl:for-each select="vuxml:name">
		      <xsl:call-template name="vuln-range">
			<xsl:with-param name="range" select="../vuxml:range" />
			<xsl:with-param name="name" select="." />
		      </xsl:call-template>
		    </xsl:for-each>
		  </xsl:for-each>
		</tbody>
	      </table></td></tr>
	</table>

	<h2 class="section">Details</h2>

	<table class="stats">
	  <xsl:call-template name="stats">
	    <xsl:with-param name="id" select="'vid'" />
	    <xsl:with-param name="label" select="'VuXML ID'" />
	    <xsl:with-param name="content" select="$vid" />
	  </xsl:call-template>

	  <xsl:for-each select="
	    vuxml:dates/vuxml:discovery	|
	    vuxml:dates/vuxml:entry	|
	    vuxml:dates/vuxml:modified">
	    <xsl:call-template name="stats">
	      <xsl:with-param name="id" select="name()" />
	      <xsl:with-param name="label"
		select="concat(translate(substring(name(), 1, 1),
		    'abcdefghijllmnopqrstuvwxyz',
		    'ABCDEFGHIJKLMNOPQRSTUVWXYZ'),
		substring(name(), 2))" />
	      <xsl:with-param name="content" select="." />
	    </xsl:call-template>
	  </xsl:for-each>
	</table>

	<div class="embed">
	  <xsl:for-each select="vuxml:description/xhtml:body">
	    <xsl:copy-of select="node()" />
	  </xsl:for-each>
	</div>

	<h2 class="section">References</h2>
	<table class="reftab">
	  <xsl:for-each select="vuxml:references/vuxml:freebsdsa">
	    <tr valign="top">
	      <td class="label">FreeBSD SA</td>
	      <td class="content"><xsl:element name="a">
		  <xsl:attribute name="href"><xsl:value-of select="concat('https://security.freebsd.org/advisories/FreeBSD-', ., '.asc')" /></xsl:attribute>
		  <xsl:value-of select="concat('FreeBSD-', .)" />
		</xsl:element></td>
	    </tr>
	  </xsl:for-each>
	  <xsl:for-each select="vuxml:references/vuxml:cvename">
	    <tr valign="top">
	      <td class="label">CVE Name</td>
	      <td class="content"><xsl:element name="a">
		  <xsl:attribute name="href"><xsl:value-of select="concat('https://cve.mitre.org/cgi-bin/cvename.cgi?name=', .)" /></xsl:attribute>
		  <xsl:value-of select="." />
		</xsl:element></td>
	    </tr>
	  </xsl:for-each>
	  <xsl:for-each select="vuxml:references/vuxml:url">
	    <tr valign="top">
	      <td class="label">URL</td>
	      <td class="content"><xsl:element name="a">
		  <xsl:attribute name="href"><xsl:value-of select="." /></xsl:attribute>
		  <xsl:value-of select="." />
		</xsl:element>
	      </td>
	    </tr>
	  </xsl:for-each>
	</table>
      </body>
    </html>
  </xsl:template>
</xsl:stylesheet>
