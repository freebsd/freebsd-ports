# Ports collection makefile for:	pear-Net_Nmap
# Date created:				13 Oct 2008
# Whom:					Wen Heping<wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net_Nmap
PORTVERSION=	1.0.2
CATEGORIES=	net pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	A Simple Wrapper Class for the Nmap Utility

BUILD_DEPENDS=	${PEARDIR}/XML/Parser.php:${PORTSDIR}/devel/pear-XML_Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Net
FILES=		Nmap.php \
		Nmap/Exception.php Nmap/Host.php \
		Nmap/Parser.php Nmap/Service.php

EXAMPLES=	example1.php example2.php example2.xml

TESTS=		NetNmapParseTest.php \
		NetNmapParseTest.xml \
		NetNmapScanTest.php \
		test_config.php \
		Bug16268Test.php \
		Bug16336Test.php \
		bug16268.xml \
		bug16336.xml

DOCS=		LICENSE README

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
