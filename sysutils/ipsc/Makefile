PORTNAME=	ipsc
PORTVERSION=	0.4.4
CATEGORIES=	sysutils
MASTER_SITES=	MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	IP Subnet Calculator
WWW=		https://codeberg.org/BSDforge/${PORTNAME}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKDIR}/${PORTNAME}/COPYING

BUILD_DEPENDS=	${PRIPS_WRKSRC}/prips.o:sysutils/prips:build

WRKSRC=		${WRKDIR}/${PORTNAME}/src

ALL_TARGET=	ipsc
PLIST_FILES=	bin/ipsc \
		share/man/man8/ipsc.8.gz

PRIPS_WRKSRC!=	cd ${.CURDIR}/../prips && ${MAKE} -V WRKSRC

post-extract:
	${LN} -s ${PRIPS_WRKSRC} ${WRKDIR}/prips

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipsc ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipsc.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
