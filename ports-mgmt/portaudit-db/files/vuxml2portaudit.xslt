<?xml version="1.0" encoding="UTF-8"?>
<!--

  $FreeBSD$

Copyright (c) 2004 Oliver Eikemeier. All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.
3. Neither the name of the author nor the names of its contributors may be
   used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND 
FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE 
COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, 
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


VuXML to portaudit database converter.

Usage:
  xsltproc -o auditfile vuxml2portaudit.xslt vuxml.xml

-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:vuxml="http://www.vuxml.org/apps/vuxml-1" version="1.0">
  <xsl:output method="text"/>
  <xsl:variable name="newline">
    <xsl:text>&#010;</xsl:text>
  </xsl:variable>
<!-- xxx -->
  <xsl:strip-space elements="vuxml:affects vuxml:package vuxml:name vuxml:range"/>
  <xsl:template match="/">
    <xsl:text># Converted by vuxml2portaudit
</xsl:text>
    <xsl:for-each select="vuxml:vuxml/vuxml:vuln">
      <xsl:variable name="topic" select="normalize-space(vuxml:topic)"/>
      <xsl:variable name="vid" select="translate(@vid, 'ABCDEF', 'abcdef')"/>
      <xsl:for-each select="vuxml:affects/vuxml:package">
        <xsl:for-each select="vuxml:name">
          <xsl:variable name="name" select="."/>
          <xsl:for-each select="../vuxml:range">
            <xsl:value-of select="$name"/>
            <xsl:apply-templates/>
            <xsl:text>|</xsl:text>
            <xsl:value-of select="$baseurl"/>
            <xsl:value-of select="$vid"/>
            <xsl:text>.html</xsl:text>
            <xsl:text>|</xsl:text>
            <xsl:value-of select="$topic"/>
            <xsl:text>|</xsl:text>
            <xsl:value-of select="$vid"/>
            <xsl:value-of select="$newline"/>
          </xsl:for-each>
        </xsl:for-each>
      </xsl:for-each>
    </xsl:for-each>
  </xsl:template>
<!-- xxx -->
  <xsl:template match="vuxml:lt">
    <xsl:text>&lt;</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
  <xsl:template match="vuxml:le">
    <xsl:text>&lt;=</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
  <xsl:template match="vuxml:gt">
    <xsl:text>&gt;</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
  <xsl:template match="vuxml:ge">
    <xsl:text>&gt;=</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
  <xsl:template match="vuxml:eq">
    <xsl:text>=</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
</xsl:stylesheet>
