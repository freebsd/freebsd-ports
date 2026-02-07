PORTNAME=	libdvbcsa
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	https://get.videolan.org/${PORTNAME}/${DISTVERSION}/ \
		https://download.videolan.org/pub/videolan/${PORTNAME}/${DISTVERSION}/

PATCH_SITES=	https://raw.githubusercontent.com/buildroot/buildroot/master/package/libdvbcsa/
PATCHFILES=	0001-altivec-powerpc64.patch:-p1

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Free implementation of the DVB Common Scrambling Algorithm
WWW=		https://www.videolan.org/developers/libdvbcsa.html

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		libtool
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>

.if defined(MACHINE_CPU) && ${MACHINE_CPU:Msse2}
CONFIGURE_ARGS+=--enable-sse2
.elif defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx}
CONFIGURE_ARGS+=--enable-mmx
.elif defined(MACHINE_CPU) && ${MACHINE_CPU:Maltivec}
CONFIGURE_ARGS+=--enable-altivec
.endif

.include <bsd.port.mk>
