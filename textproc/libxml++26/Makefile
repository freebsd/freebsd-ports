# ex:ts=8
# New ports collection makefile for:	libxml++
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/libxml++26/Makefile,v 1.37 2010/04/03 16:02:01 avl Exp $
#

PORTNAME=	libxml++
PORTVERSION=	2.30.0
PORTREVISION?=	0
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	bland@FreeBSD.org
COMMENT=	XML API for C++

USE_BZIP2=	yes

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6"

.if !defined(REFERENCE_PORT)

LATEST_LINK=	libxml++26

LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_GMAKE=	yes
USE_GNOME=	gnomehack libxml2 pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--enable-static --disable-documentation

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^gentoo_ltmain_version=/s/`.*`/$$gentoo_lt_version/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^library_configdir =/s/libdir/includedir/' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^Cflags:/s/libdir/includedir/' \
		${WRKSRC}/libxml++-2.6.pc.in

.include <bsd.port.mk>

.endif