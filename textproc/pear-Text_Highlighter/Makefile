# Ports collection makefile for:  pear-File_Highlighter
# Date created:			28 Dec 2007
# Whom:				Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text_Highlighter
PORTVERSION=	0.7.1
CATEGORIES=	textproc pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Syntax highlighting

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser

CATEGORY=	Text
FILES=		Highlighter.php abap.xml cpp.xml css.xml diff.xml \
		dtd.xml generate generate.bat html.xml java.xml  \
		javascript.xml mysql.xml perl.xml php.xml python.xml \
		ruby.xml sample.css sh.xml sql.xml vbscript.xml xml.xml \
		Highlighter/ABAP.php Highlighter/CPP.php Highlighter/CSS.php \
		Highlighter/DIFF.php Highlighter/DTD.php Highlighter/Generator.php \
		Highlighter/HTML.php Highlighter/JAVA.php Highlighter/JAVASCRIPT.php \
		Highlighter/MYSQL.php Highlighter/PERL.php Highlighter/PHP.php \
		Highlighter/PYTHON.php Highlighter/RUBY.php Highlighter/Renderer.php \
		Highlighter/SH.php Highlighter/SQL.php Highlighter/VBSCRIPT.php \
		Highlighter/XML.php Highlighter/Renderer/Array.php Highlighter/Renderer/BB.php \
		Highlighter/Renderer/Console.php Highlighter/Renderer/Html.php \
		Highlighter/Renderer/HtmlTags.php Highlighter/Renderer/JSON.php \
		Highlighter/Renderer/XML.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
