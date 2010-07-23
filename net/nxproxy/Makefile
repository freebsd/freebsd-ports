# New ports collection makefile for:	nxproxy
# Date created:				2010-06-24
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	nxproxy
DISTVERSION=	3.4.0-2
CATEGORIES=	net
MASTER_SITES=	http://x2go.obviously-nice.de/deb/pool-lenny/nxproxy/:nxproxy \
		http://x2go.obviously-nice.de/deb/pool-lenny/nxcomp/:nxcomp
DISTFILES=	nxcomp-${DISTVERSION:S/2/1/}.tar.gz:nxcomp\
		nxproxy-${DISTVERSION}.tar.gz:nxproxy

MAINTAINER=	arved@FreeBSD.org
COMMENT=	An x2go helper program

LIB_DEPENDS=	png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE
CONFLICTS=	nxserver-[0-9]*
GNU_CONFIGURE=	yes
USE_XORG=	ice x11 sm
PLIST_FILES=	bin/nxproxy

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not compile on 6.X
.endif

post-extract:
	${LN} -sf ${WRKDIR}/nxcomp-${DISTVERSION:S/2/1/} ${WRKDIR}/nxcomp

post-patch:
	${REINPLACE_CMD} -e "s,-O3,${CFLAGS}," ${WRKSRC}/configure \
		${WRKDIR}/nxcomp/configure
	${REINPLACE_CMD} -e "s,-lXcomp, -L${PREFIX}/lib -lpng -ljpeg ../nxcomp/libXcomp.a," \
		${WRKSRC}/configure

pre-configure:
	cd ${WRKDIR}/nxcomp; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS};

pre-build:
	cd ${WRKDIR}/nxcomp; ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nxproxy ${PREFIX}/bin

.include <bsd.port.post.mk>
