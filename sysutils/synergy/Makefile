# $FreeBSD$

PORTNAME=	synergy
PORTVERSION=	1.5.1
DISTVERSIONSUFFIX=	-Source
CATEGORIES=	sysutils
MASTER_SITES=	http://synergy-project.org/files/packages/
DISTNAME=	${PORTNAME}-${PORTVERSION}-r2398${DISTVERSIONSUFFIX}

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Mouse and keyboard sharing utility

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}${DISTVERSIONSUFFIX}
USES=		cmake
USE_XORG=	ice xtst x11 sm

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

MAKE_JOBS_UNSAFE=yes

CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib

PLIST_FILES=    bin/synergyc bin/synergyd bin/synergys bin/syntool \
		man/man1/synergyc.1.gz man/man1/synergys.1.gz
PORTEXAMPLES=	synergy.conf.example synergy.conf.example-basic \
		synergy.conf.example-advanced

OPTIONS_DEFINE=	EXAMPLES

post-extract:
	cd ${WRKSRC}/ext/
	${MKDIR} ${WRKSRC}/ext/cryptopp562
	(cd ${WRKSRC}/ext/cryptopp562 && ${TAR} xfz ${WRKSRC}/ext/cryptopp562.zip)

do-install:
.for f in synergyc synergyd synergys syntool
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/synergyc.man \
		${STAGEDIR}${MANPREFIX}/man/man1/synergyc.1
	${INSTALL_MAN} ${WRKSRC}/doc/synergys.man \
		${STAGEDIR}${MANPREFIX}/man/man1/synergys.1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for f in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
