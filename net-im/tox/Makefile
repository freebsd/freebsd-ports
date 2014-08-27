# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	toxcore
PORTVERSION=	0.140814
PORTREVISION=	1
CATEGORIES=	net-im net-p2p

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	ProjectTox-Core library, a decentralized and secure messenger

LICENSE=	GPLv3

BUILD_DEPENDS=	checkmk:${PORTSDIR}/devel/libcheck
LIB_DEPENDS=	libvpx.so:${PORTSDIR}/multimedia/libvpx		\
		libopus.so:${PORTSDIR}/audio/opus		\
		libopenal.so.1:${PORTSDIR}/audio/openal-soft	\
		libv4l2.so:${PORTSDIR}/multimedia/libv4l	\
		libswscale.so:${PORTSDIR}/multimedia/ffmpeg

USE_GITHUB=	yes
GH_ACCOUNT=	irungentoo
GH_PROJECT=	${PORTNAME}
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	7557b92

USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f
CONFIGURE_ARGS=	--enable-testing
USES=		pkgconfig pathfix libtool
USE_SDL=	yes
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALL_TARGET=		install-strip

OPTIONS_RADIO=		CRYPTO
OPTIONS_RADIO_CRYPTO=	SODIUM NACL
OPTIONS_DEFAULT=	SODIUM
OPTIONS_SUB=		yes

SODIUM_DESC=		Prefer libsodium
SODIUM_LIB_DEPENDS=	libsodium.so:${PORTSDIR}/security/libsodium

NACL_DESC=		Prefer NaCl
NACL_CONFIGURE_ENABLE=	nacl
NACL_BUILD_DEPENDS=	${LOCALBASE}/lib/libnacl.a:${PORTSDIR}/security/nacl
NACL_RUN_DEPENDS=	${LOCALBASE}/lib/libnacl.a:${PORTSDIR}/security/nacl

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
USE_GCC=	yes
BROKEN_i386=	'__stack_chk_fail_local' isn't defined
.endif

.if ${PORT_OPTIONS:MNACL}
CONFIGURE_ARGS+=	--with-nacl-libs=${LOCALBASE}/lib
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
