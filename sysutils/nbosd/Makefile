# New ports collection makefile for:	nbosd
# Date created:				19 Mar 2006
# Whom:					Lars Engels <lars.engels@0x20.net>
#
# $FreeBSD$
#

PORTNAME=	nbosd
PORTVERSION=	0.4.2
CATEGORIES=	sysutils
MASTER_SITES=	http://bsd-geek.de/FreeBSD/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lars.engels@0x20.net
COMMENT=	Displays battery life and CPU frequency with an OSD

BUILD_DEPENDS=	xosd-config:${PORTSDIR}/misc/xosd

USE_X_PREFIX=	yes
PLIST_FILES=	bin/nbosd
PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nbosd ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}/
.endif

.include <bsd.port.mk>
