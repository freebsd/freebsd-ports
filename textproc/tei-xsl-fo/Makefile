# New ports collection makefile for:	tei-xsl-fo
# Date created:				19 May 2002
# Whom:					Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	tei
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.tei-c.org/Stylesheets/
PKGNAMESUFFIX=	-xsl-fo
DISTNAME=	teixsl-fo

MAINTAINER=	henrik.motakef@web.de

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
INSTDIR=	${PREFIX}/share/xsl/tei/fo

do-install:
	@[ -d ${INSTDIR} ] || ${MKDIR} ${INSTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.xsl ${INSTDIR}

.include <bsd.port.mk>
