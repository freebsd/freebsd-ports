# New ports collection makefile for:	ipsc
# Date created:		31 October 1999
# Whom:			Jeremy Shaffner <jeremy@external.org>
#
# $FreeBSD$
#

PORTNAME=	ipsc
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.alaskaparadise.com/freebsd/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IP Subnet Calculator

BUILD_DEPENDS=	${PRIPS_WRKSRC}/prips.o:${.CURDIR}/../prips:build

WRKSRC=		${WRKDIR}/ipsc/src

WANT_GNOME=	yes
PLIST_FILES=	bin/ipsc

MAN8=	ipsc.8

.if defined(HAVE_GNOME)
USE_GNOME=	gnomeprefix gnomehack gtkhtml
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
	${INSTALL_MAN} ${FILESDIR}/ipsc.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
