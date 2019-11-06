# Created by: Romain Tartiere <romain@blogreen.org>
# $FreeBSD$

PORTNAME=	podsleuth
PORTVERSION=	0.6.7
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://download.banshee.fm/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Tool to discover detailed model information about an iPod

BROKEN=		unfetchable

LIB_DEPENDS=	libsgutils2.so:sysutils/sg3_utils \
		libhal.so:sysutils/hal
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:devel/ndesk-dbus
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-1.0.pc:devel/ndesk-dbus

CONFIGURE_ARGS+=--with-hal-callouts-dir=${PREFIX}/libexec
CONFIGURE_ENV=	ac_cv_path_MCS=${LOCALBASE}/bin/mcs
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USES=		gmake mono pkgconfig pathfix
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/bash$$|#!/bin/sh|' \
	    ${WRKSRC}/src/PodSleuth.Hal/hal-podsleuth.in \
	    ${WRKSRC}/src/PodSleuth.Hal/podsleuth.in \

.include <bsd.port.mk>
