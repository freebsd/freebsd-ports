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
COMMENT=	Helper program for x2go

LICENSE=	GPLv2

LIB_DEPENDS=	libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

CONFLICTS=	nxserver-[0-9]*

USE_XORG=	ice x11 sm
USE_GCC=	any
USE_AUTOTOOLS=	autoconf

CPPFLAGS+=	$$(libpng-config --I_opts)
LDFLAGS+=	$$(libpng-config --L_opts)

PLIST_FILES=	bin/nxproxy bin/setsid

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc" && ${OSVERSION} > 900000
BROKEN=		Does not link on powerpc-9
.endif

post-extract:
	${LN} -sf ${WRKDIR}/nxcomp-${DISTVERSION:S/2/1/} ${WRKDIR}/nxcomp

post-patch:
	@${REINPLACE_CMD} -e \
		'/-O3/s|^|#|' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e \
		'/-O3/s|^|#|' ${WRKDIR}/nxcomp/configure.in
	@${REINPLACE_CMD} -e \
		's|-Wpointer-arith|@CPPFLAGS@|' ${WRKDIR}/nxcomp/Makefile.in

pre-configure:
	cd ${WRKDIR}/nxcomp; ${AUTOCONF}
	cd ${WRKDIR}/nxcomp; ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} \
		${CONFIGURE_ARGS} --without-symbols \
		CC="${CC}" CFLAGS="${CFLAGS}" \
		CXX="${CXX}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

pre-build:
	cd ${WRKDIR}/nxcomp; ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${FILESDIR}/setsid.c -o setsid

do-install:
.for i in nxproxy setsid
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} ${i} ${STAGEDIR}${PREFIX}/bin)
.endfor

.include <bsd.port.post.mk>
