# New ports collection makefile for:	ipsc
# Date created:		31 October 1999
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	ipsc
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://ipsc.sourceforge.net/dist/ipsc/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jeremy@external.org
COMMENT=	An IP Subnet Calculator

BUILD_DEPENDS=	${PRIPS_WRKSRC}/prips.o:${.CURDIR}/../prips:build

WRKSRC=		${WRKDIR}/ipsc/src

WANT_GNOME=	yes
PLIST_FILES=	bin/ipsc

.if defined(HAVE_GNOME)
USE_X_PREFIX=	yes
USE_GNOME=	yes
ALL_TARGET=	all
PLIST_FILES+=	bin/gipsc
.else
ALL_TARGET=	ipsc
.endif

PRIPS_WRKSRC!=	cd ${.CURDIR}/../prips && ${MAKE} -V WRKSRC

post-extract:
	${LN} -s ${PRIPS_WRKSRC} ${WRKDIR}/prips

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipsc ${PREFIX}/bin
.if defined(HAVE_GNOME)
	${INSTALL_PROGRAM} ${WRKSRC}/gipsc ${PREFIX}/bin
.endif

.include <bsd.port.mk>
