# New ports collection makefile for:	tei-xsl
# Date created:				19 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Stylesheets/
PKGNAMESUFFIX=	-xsl-html
DISTNAME=	teixsl-html

MAINTAINER=	henrik.motakef@web.de

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
INSTDIR=	${PREFIX}/share/xsl/tei/html

do-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.xsl ${INSTDIR}

.include <bsd.port.mk>
