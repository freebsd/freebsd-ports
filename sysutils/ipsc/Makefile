# Created by: Jeremy Shaffner <jeremy@external.org>
# $FreeBSD$

PORTNAME=	ipsc
PORTVERSION=	0.4.3
CATEGORIES=	sysutils
MASTER_SITES=	http://archive.debian.org/debian/pool/main/i/ipsc/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	cy@FreeBSD.org
COMMENT=	IP Subnet Calculator

BUILD_DEPENDS=	${PRIPS_WRKSRC}/prips.o:sysutils/prips:build

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

ALL_TARGET=	ipsc
PLIST_FILES=	bin/ipsc man/man8/ipsc.8.gz

PRIPS_WRKSRC!=	cd ${.CURDIR}/../prips && ${MAKE} -V WRKSRC

post-extract:
	${LN} -s ${PRIPS_WRKSRC} ${WRKDIR}/prips

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipsc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/ipsc.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
