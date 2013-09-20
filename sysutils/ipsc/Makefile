# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	ipsc
PORTVERSION=	0.4.3
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.debian.org/debian/pool/main/i/ipsc/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	cy@FreeBSD.org
COMMENT=	An IP Subnet Calculator

BUILD_DEPENDS=	${PRIPS_WRKSRC}/prips.o:${PORTSDIR}/sysutils/prips:build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

ALL_TARGET=	ipsc
PLIST_FILES=	bin/ipsc

MAN8=	ipsc.8

PRIPS_WRKSRC!=	cd ${.CURDIR}/../prips && ${MAKE} -V WRKSRC

NO_STAGE=	yes
post-extract:
	${LN} -s ${PRIPS_WRKSRC} ${WRKDIR}/prips

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipsc ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/ipsc.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
