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


VuXML to HTML converter.

Usage:
  xsltproc -o html/ vuxml2html.xslt vuxml.xml

-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xhtml="http://www.w3.org/1999/xhtml" xmlns:vuxml="http://www.vuxml.org/apps/vuxml-1" xmlns="http://www.w3.org/1999/xhtml" exclude-result-prefixes="xhtml vuxml" version="1.0">
  <xsl:output method="xml"/>
  <xsl:strip-space elements="vuxml:affects vuxml:package vuxml:name vuxml:range" />
<!-- whole vuxml file -->
  <xsl:template match="vuxml:vuxml">
<!-- index page, xhtml strict -->
    <xsl:document href="index.html" method="xml" indent="yes" encoding="UTF-8" doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
      <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
        <head>
          <title>portaudit: Vulnerability list</title>
          <xsl:call-template name="css"/>
        </head>
        <body>
          <div>
            <xsl:call-template name="bar"/>
          </div>
          <h1>Vulnerabilities</h1>
          <table>
            <xsl:for-each select="vuxml:vuln | document($extradoc)/vuxml:vuxml/vuxml:vuln">
              <xsl:sort select="(vuxml:dates/vuxml:modified | vuxml:dates/vuxml:entry)[1]" order="descending"/>
              <tr>
                <td>
                  <xsl:value-of select="(vuxml:dates/vuxml:modified | vuxml:dates/vuxml:entry)[1]"/>
                </td>
                <td>
                  <a href="{translate(@vid, 'ABCDEF', 'abcdef')}.html">
                    <xsl:value-of select="vuxml:topic"/>
                  </a>
                </td>
              </tr>
            </xsl:for-each>
          </table>
          <p>
            <a href="index-pkg.html">[Sorted by package name]</a>
          </p>
          <xsl:call-template name="foo">
            <xsl:with-param name="vid">index</xsl:with-param>
          </xsl:call-template>
        </body>
      </html>
    </xsl:document>
<!-- index page by packages, xhtml strict -->
    <xsl:document href="index-pkg.html" method="xml" indent="yes" encoding="UTF-8" doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
      <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
        <head>
          <title>portaudit: Vulnerability list by packages</title>
          <xsl:call-template name="css"/>
        </head>
        <body>
          <div>
            <xsl:call-template name="bar"/>
          </div>
          <h1>Vulnerabilities</h1>
          <table>
            <xsl:for-each select="//vuxml:affects/vuxml:package/vuxml:name | document($extradoc)//vuxml:affects/vuxml:package/vuxml:name">
              <xsl:sort select="translate(., 'ABCDEFGHIJKLMNOPQRSTUVWXYZ', 'abcdefghijklmnopqrstuvwxyz')"/>
              <xsl:sort select="(ancestor-or-self::vuxml:vuln/vuxml:dates/vuxml:modified | ancestor-or-self::vuxml:vuln/vuxml:dates/vuxml:entry)[1]" order="descending"/>
              <tr>
                <td>
                  <xsl:value-of select="."/>
                </td>
                <td>
                  <a href="{translate(ancestor-or-self::vuxml:vuln/@vid, 'ABCDEF', 'abcdef')}.html">
                    <xsl:value-of select="ancestor-or-self::vuxml:vuln/vuxml:topic"/>
                  </a>
                </td>
              </tr>
            </xsl:for-each>
          </table>
          <p>
            <a href="index.html">[Sorted by last modification]</a>
          </p>
          <xsl:call-template name="foo">
            <xsl:with-param name="vid">index</xsl:with-param>
          </xsl:call-template>
        </body>
      </html>
    </xsl:document>
<!-- individual pages, xhtml strict -->
    <xsl:for-each select="vuxml:vuln | document($extradoc)/vuxml:vuxml/vuxml:vuln">
      <xsl:document href="{translate(@vid, 'ABCDEF', 'abcdef')}.html" method="xml" indent="yes" encoding="UTF-8" doctype-public="-//W3C//DTD XHTML 1.0 Strict//EN" doctype-system="http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
        <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
          <head>
            <xsl:choose>
              <xsl:when test="vuxml:cancelled">
                <title>portaudit: Cancelled entry</title>
              </xsl:when>
              <xsl:otherwise>
                <title>portaudit: <xsl:value-of select="vuxml:topic"/></title>
              </xsl:otherwise>
            </xsl:choose>
            <xsl:call-template name="css"/>
          </head>
          <body>
            <div>
              <xsl:call-template name="bar"/>
            </div>
            <xsl:choose>
              <xsl:when test="vuxml:cancelled">
                <h1>
                  Cancelled entry
                </h1>
                <xsl:if test="vuxml:cancelled/@superseded">
                  <h2>References:</h2>
                  <ul>
                    <li>Superseded by <a href="./{vuxml:cancelled/@superseded}.html">entry
                        <xsl:value-of select="vuxml:cancelled/@superseded"/></a></li>
                  </ul>
                </xsl:if>
              </xsl:when>
              <xsl:otherwise>
                <h1>
                  <xsl:value-of select="vuxml:topic"/>
                </h1>
                <h2>Description:</h2>
                <xsl:copy-of select="vuxml:description/xhtml:body/*"/>
                <h2>References:</h2>
                <ul>
                  <xsl:apply-templates select="vuxml:references"/>
                </ul>
                <h2>Affects:</h2>
                <ul>
                  <xsl:for-each select="vuxml:affects/vuxml:package">
                    <xsl:for-each select="vuxml:name">
                      <xsl:variable name="name" select="."/>
                      <xsl:for-each select="../vuxml:range">
                        <li>
                          <xsl:value-of select="$name"/>
                          <xsl:apply-templates/>
                        </li>
                      </xsl:for-each>
                    </xsl:for-each>
                  </xsl:for-each>
                  <xsl:for-each select="vuxml:affects/vuxml:system">
                    <xsl:for-each select="vuxml:name">
                      <xsl:variable name="name" select="."/>
                      <xsl:for-each select="../vuxml:range">
                        <li>
                          <xsl:value-of select="$name"/>
                          <xsl:apply-templates/>
                        </li>
                      </xsl:for-each>
                    </xsl:for-each>
                  </xsl:for-each>
                </ul>
                <title>portaudit: <xsl:value-of select="vuxml:topic"/></title>
              </xsl:otherwise>
            </xsl:choose>

            <xsl:call-template name="foo">
              <xsl:with-param name="vid" select="@vid"/>
            </xsl:call-template>
          </body>
        </html>
      </xsl:document>
    </xsl:for-each>
<!-- end of vuxml file processing -->
  </xsl:template>
<!-- vulnerability references -->
  <xsl:template match="vuxml:bid">
    <li>BugTraq ID <a href="http://www.securityfocus.com/bid/{.}"><xsl:value-of select="."/></a></li>
  </xsl:template>
  <xsl:template match="vuxml:certsa">
    <li>CERT security advisory <a href="http://www.cert.org/advisories/{.}.html"><xsl:value-of select="."/></a></li>
  </xsl:template>
  <xsl:template match="vuxml:certvu">
    <li>CERT vulnerability note <a href="http://www.kb.cert.org/vuls/id/{.}"><xsl:value-of select="."/></a></li>
  </xsl:template>
  <xsl:template match="vuxml:cvename">
    <li>CVE name <a href="http://cve.mitre.org/cgi-bin/cvename.cgi?name={.}"><xsl:value-of select="."/></a></li>
  </xsl:template>
  <xsl:template match="vuxml:freebsdsa">
    <li>FreeBSD security advisory <a href="ftp://ftp.freebsd.org/pub/FreeBSD/CERT/advisories/FreeBSD-{.}.asc">FreeBSD-<xsl:value-of select="."/></a></li>
  </xsl:template>
  <xsl:template match="vuxml:freebsdpr">
    <li>FreeBSD PR <a href="http://www.freebsd.org/cgi/query-pr.cgi?pr={.}"><xsl:value-of select="."/></a></li>
  </xsl:template>
  <xsl:template match="vuxml:mlist">
    <li>List post: <a href="{.}">&lt;<xsl:value-of select="."/>&gt;</a>
      <xsl:if test="@msgid"><a href="http://www.google.com/search?q={@msgid}">(search)</a></xsl:if>
    </li>
  </xsl:template>
  <xsl:template match="vuxml:url">
    <li>URL: <a href="{.}">&lt;<xsl:value-of select="."/>&gt;</a></li>
  </xsl:template>
  <xsl:template match="vuxml:uscertsa">
    <li>US-CERT security alert <a href="http://www.us-cert.gov/cas/alerts/{.}.html"><xsl:value-of select="."/></a></li>
  </xsl:template>
  <xsl:template match="vuxml:uscertta">
    <li>US-CERT technical security alert <a href="http://www.us-cert.gov/cas/techalerts/{.}.html"><xsl:value-of select="."/></a></li>
  </xsl:template>
<!-- comparison operators -->
  <xsl:template match="vuxml:lt">
    <xsl:text> &lt;</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
  <xsl:template match="vuxml:le">
    <xsl:text> &lt;=</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
  <xsl:template match="vuxml:gt">
    <xsl:text> &gt;</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
  <xsl:template match="vuxml:ge">
    <xsl:text> &gt;=</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
  <xsl:template match="vuxml:eq">
    <xsl:text> =</xsl:text>
    <xsl:value-of select="text()"/>
  </xsl:template>
<!-- style sheet -->
  <xsl:template name="css">
    <link rel="shortcut icon" href="http://www.freebsd.org/favicon.ico" type="image/x-icon"/>
    <style type="text/css">
      <xsl:comment>
        <xsl:text>
        body {
          background-color : #ffffff;
          color : #000000;
        }

        a:link { color: #0000ff }
        a:visited { color: #840084 }
        a:active { color: #0000ff }

        h1 { color: #990000 }

        img { color: white; border:none }

        table {
          border: none;
          margin-top: 10px;
          margin-bottom: 10px;
        }

        th {
          text-align: left;
          padding: 3px;
          border: none;
          vertical-align: top;
        }

        td {
          padding: 3px;
          border: none;
          vertical-align: top;
        }

        tr.odd {
          background: #eeeeee;
          color: inherit;
        }
      </xsl:text>
      </xsl:comment>
    </style>
  </xsl:template>
<!-- xhtml elements -->
  <xsl:template name="bar">
    <img src="http://www.freebsd.org/gifs/bar.gif" alt="Navigation Bar" height="33" width="565" usemap="#bar"/>
    <map id="bar" name="bar">
      <area shape="rect" coords="1,1,111,33" href="http://www.freebsd.org/" alt="Top"/>
      <area shape="rect" coords="112,16,196,33" href="http://www.freebsd.org/ports/index.html" alt="Applications"/>
      <area shape="rect" coords="197,16,256,33" href="http://www.freebsd.org/support.html" alt="Support"/>
      <area shape="rect" coords="257,16,365,33" href="http://www.freebsd.org/docs.html" alt="Documentation"/>
      <area shape="rect" coords="366,16,424,33" href="http://www.freebsd.org/commercial/commercial.html" alt="Vendors"/>
      <area shape="rect" coords="425,16,475,33" href="http://www.freebsd.org/search/search.html" alt="Search"/>
      <area shape="rect" coords="476,16,516,33" href="http://www.freebsd.org/search/index-site.html" alt="Index"/>
      <area shape="rect" coords="517,16,565,33" href="http://www.freebsd.org/" alt="Top"/>
      <area shape="rect" coords="0,0,565,33" href="http://www.freebsd.org/" alt="Top"/>
    </map>
  </xsl:template>
  <xsl:template name="foo">
    <xsl:param name="vid"/>
    <hr/>
    <p><strong>Disclaimer:</strong> The data contained on this page is derived from the VuXML document,
    please refer to the <a href="{$vulurl}">the original document</a> for copyright information. The author of
    portaudit makes no claim of authorship or ownership of any of the information contained herein.</p>
      <p>
        If you have found a vulnerability in a FreeBSD port not listed in the
        database, please <a href="mailto:security@FreeBSD.org?subject=vid%20{$vid}">contact
        the FreeBSD Security Team</a>. Refer to
        <a href="http://www.freebsd.org/security/#how">"FreeBSD Security
        Information"</a> for more information.
        </p>
    <hr/>
    <address title="Oliver Eikemeier">
      Oliver Eikemeier <a href="mailto:eik@FreeBSD.org?subject=portaudit">&lt;eik@FreeBSD.org&gt;</a>
    </address>
  </xsl:template>
</xsl:stylesheet>
