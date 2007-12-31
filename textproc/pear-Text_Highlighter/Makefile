# Ports collection makefile for:  pear-File_Highlighter
# Date created:			28 Dec 2007
# Whom:				Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Text_Highlighter
PORTVERSION=	0.7.0
CATEGORIES=	textproc pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Syntax highlighting

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser

CATEGORY=	Text
FILES=		Highlighter.php abap.xml diff.xml generate.bat \
		javascript.xml php.xml sample.css cpp.xml dtd.xml \
		html.xml mysql.xml python.xml sql.xml \
		Highlighter/ABAP.php Highlighter/CSS.php Highlighter/DTD.php \
		Highlighter/HTML.php Highlighter/JAVASCRIPT.php Highlighter/PERL.php \
		Highlighter/PYTHON.php Highlighter/SQL.php Highlighter/CPP.php \
		Highlighter/DIFF.php Highlighter/Generator.php Highlighter/JAVA.php \
		Highlighter/MYSQL.php Highlighter/PHP.php Highlighter/RUBY.php \
		Highlighter/Renderer.php Highlighter/XML.php \
		Highlighter/Renderer/Array.php Highlighter/Renderer/BB.php \
		Highlighter/Renderer/Console.php Highlighter/Renderer/Html.php \
		Highlighter/Renderer/HtmlTags.php Highlighter/Renderer/JSON.php \
		Highlighter/Renderer/XML.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
