# Created by: Bernhard Froehlich <decke@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdvbcsa
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://download.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://ftp.heikorichter.name/pub/videolan/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Free implementation of the DVB Common Scrambling Algorithm

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
.endif

.include <bsd.port.mk>
