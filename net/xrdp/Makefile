# Created by: alepulver
# $FreeBSD$

PORTNAME=	xrdp
PORTVERSION=	0.6.1
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	GH
DIST_SUBDIR?=	${PORTNAME}

PATCH_SITES=	http://www.club.kyutech.ac.jp/~meta/patches/xrdp/0.6.0/ \
		http://key2.jp/~meta/patches/xrdp/0.6.0/

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Open source Remote Desktop Protocol (RDP) server

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig
USE_XORG=	x11 xfixes
USE_AUTOTOOLS=	autoconf:env automake:env libtool
GNU_CONFIGURE=	yes
USE_RC_SUBR=	xrdp
USE_GITHUB=	yes
GH_ACCOUNT=	FreeRDP
GH_PROJECT=	xrdp
GH_COMMIT=	5d53758
GH_TAGNAME=	${GH_COMMIT}

CONFIGURE_ARGS=	--localstatedir=/var --enable-freerdp1
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFLICTS=	xrdp-devel-[0-9]*
BUILD_DEPENDS+=	freerdp>=1.0.2:${PORTSDIR}/net/freerdp

USE_LDCONFIG=	${STAGEDIR}${PREFIX}/lib/xrdp

OPTIONS_DEFINE=	DEBUG JP106
OPTIONS_DEFAULT=	JP106 TIGERVNC
OPTIONS_RADIO=	XVNC
OPTIONS_RADIO_XVNC=	REALVNC TIGERVNC TIGHTVNC TRIDIAVNC
REALVNC_DESC=	Use RealVNC
TIGERVNC_DESC=	Use TigerVNC (recommended)
TIGHTVNC_DESC=	Use TightVNC
TRIDIAVNC_DESC=	Use TridiaVNC
JP106_DESC=	Install Japanese JP106 keymap

.include <bsd.port.options.mk>

# Which Xserver to use
.if ${PORT_OPTIONS:MREALVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/vnc
.endif
.if ${PORT_OPTIONS:MTIGERVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tigervnc
.endif
.if ${PORT_OPTIONS:MTIGHTVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tightvnc
.endif
.if ${PORT_OPTIONS:MTRIDIAVNC}
RUN_DEPENDS=	Xvnc:${PORTSDIR}/net/tridiavnc
.endif

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-xrdpdebug
CFLAGS+=	-DXRDP_DEBUG
.endif

.if ${PORT_OPTIONS:MJP106}
PATCHFILES+=	patch-instfiles__Makefile.am \
	patch-instfiles__km-0411.ini \
	patch-instfiles__km-e0010411.ini \
	patch-instfiles__km-e0200411.ini \
	patch-instfiles__km-e0210411.ini
PLIST_SUB+=	JP106=""
.else
PLIST_SUB+=	JP106="@comment "
.endif

SUB_FILES=	pkg-message

post-patch:
.for f in sesman/sesman.ini sesman/startwm.sh xrdp/rsakeys.ini xrdp/xrdp.ini
	@${MV} ${WRKSRC}/$f ${WRKSRC}/$f.sample
.endfor

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

post-install:
.for f in sesman.ini startwm.sh xrdp.ini
	@if [ ! -f ${STAGEDIR}${PREFIX}/etc/xrdp/$f ]; then \
		${CP} -p ${STAGEDIR}${PREFIX}/etc/xrdp/$f.sample ${STAGEDIR}${PREFIX}/etc/xrdp/$f ; \
	fi
.endfor

.include <bsd.port.mk>
