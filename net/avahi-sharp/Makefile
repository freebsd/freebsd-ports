# New ports collection makefile for:	avahi-sharp
# Date Created:				20041011
# Whom:					Tom McLaughlin <tmclaugh@FreeBSD.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.2 2006/02/15 19:15:40 tmclau02 Exp $
#

PORTREVISION=	0
CATEGORIES=	net dns
PKGNAMESUFFIX=	-sharp

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	Mono bindings for Avahi service discovery

LIB_DEPENDS=	avahi-core:${PORTSDIR}/net/avahi-app
BUILD_DEPENDS=	mono:${PORTSDIR}/lang/mono
RUN_DEPENDS=	mono:${PORTSDIR}/lang/mono

MASTERDIR=	${.CURDIR}/../avahi-app
BUILD_WRKSRC=	${WRKSRC}/avahi-sharp
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

AVAHI_SLAVE=	sharp
AVAHI_PKGCONFIG=avahi-sharp.pc

post-patch:
	@${REINPLACE_CMD} 's|@CLIENT_DLNAME@|libavahi-client.so|g; \
		s|@COMMON_DLNAME@|libavahi-common.so|g; \
		s|@GLIB_DLNAME@|libavahi-glib.so|g' \
		${BUILD_WRKSRC}/avahi-sharp.dll.config.in
	@${CP} ${WRKSRC}/avahi-sharp/avahi-sharp.dll.config.in ${WRKSRC}/avahi-sharp/avahi-sharp.dll.config

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include "${MASTERDIR}/Makefile"
