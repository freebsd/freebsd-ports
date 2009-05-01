# Ports collection makefile for:  pear-XML_DTD
# Date created:			  2006/07/31
# Whom:				  chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	XML_DTD
PORTVERSION=	0.5.2
CATEGORIES=	textproc devel pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Parsing of DTD files and DTD validation of XML files

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear \
		${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_DOS2UNIX=	yes

CATEGORY=	XML
FILES=		DTD/XmlValidator.php DTD.php
TESTS=		attributes.dtd attributes_bad.xml attributes_good.xml \
		children.dtd children_bad.xml children_good.xml \
		content.dtd content_bad.xml content_good.xml \
		nitf-3-1.dtd nitf-fishing.xml package-1.0 package-1.1.dtd \
		test.php TOTEST xhtml1-strict.dtd

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
