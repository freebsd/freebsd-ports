# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	podsleuth
PORTVERSION=	0.6.7
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://download.banshee.fm/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	A tool to discover detailed model information about an iPod

LIB_DEPENDS=	sgutils2.2:${PORTSDIR}/sysutils/sg3_utils \
		hal.1:${PORTSDIR}/sysutils/hal
BUILD_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus
RUN_DEPENDS=	${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:${PORTSDIR}/devel/ndesk-dbus

CONFIGURE_ARGS+=--with-hal-callouts-dir=${PREFIX}/libexec
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig pathfix

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/bash$$|#!/bin/sh|' \
	    ${WRKSRC}/src/PodSleuth.Hal/hal-podsleuth.in \
	    ${WRKSRC}/src/PodSleuth.Hal/podsleuth.in \

.include <bsd.port.mk>
