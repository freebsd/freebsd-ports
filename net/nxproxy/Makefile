# Created by: arved
# $FreeBSD$

PORTNAME=	nxproxy
DISTVERSION=	3.4.0-2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://x2go.obviously-nice.de/deb/pool-lenny/nxproxy/:nxproxy \
		http://x2go.obviously-nice.de/deb/pool-lenny/nxcomp/:nxcomp
DISTFILES=	nxcomp-${DISTVERSION:S/2/1/}.tar.gz:nxcomp\
		nxproxy-${DISTVERSION}.tar.gz:nxproxy

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An x2go helper program

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE
CONFLICTS=	nxserver-[0-9]*
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_XORG=	ice x11 sm
CXXFLAGS+=	-I${LOCALBASE}/include/libpng15
CONFIGURE_ENV+=	CXXFLAGS="${CXXFLAGS}"
PLIST_FILES=	bin/nxproxy bin/setsid

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not link on powerpc-9
.endif

post-extract:
	${LN} -sf ${WRKDIR}/nxcomp-${DISTVERSION:S/2/1/} ${WRKDIR}/nxcomp

post-patch:
	${REINPLACE_CMD} -e "s,-O3,${CFLAGS}," ${WRKSRC}/configure.in \
		${WRKDIR}/nxcomp/configure.in
	${REINPLACE_CMD} -e "s,-lXcomp, -L${PREFIX}/lib -lpng -ljpeg ../nxcomp/libXcomp.a," \
		${WRKSRC}/configure.in
.if ${OSVERSION} < 700000
	${REINPLACE_CMD} -e "s,result = unsetenv,unsetenv," ${WRKDIR}/nxcomp/Children.cpp
.endif

pre-configure:
	cd ${WRKDIR}/nxcomp; ${AUTOCONF}
	cd ${WRKDIR}/nxcomp; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS};

pre-build:
	cd ${WRKDIR}/nxcomp; ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${FILESDIR}/setsid.c -o setsid

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nxproxy ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/setsid ${PREFIX}/bin

.include <bsd.port.post.mk>
