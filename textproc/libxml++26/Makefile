# ex:ts=8
# New ports collection makefile for:	libxml++
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/libxml++26/Makefile,v 1.35 2009/03/17 14:57:40 kwm Exp $
#

PORTNAME=	libxml++
PORTVERSION=	2.26.1
CATEGORIES=	textproc
MASTER_SITES=	GNOME

MAINTAINER=	bland@FreeBSD.org
COMMENT=	XML API for C++

LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

LATEST_LINK=	libxml++26

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack libxml2 pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6" DOC_VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^gentoo_ltmain_version=/s/`.*`/$$gentoo_lt_version/' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^library_configdir =/s/libdir/includedir/' \
	    	${WRKSRC}/libxml++/Makefile.in
	@${REINPLACE_CMD} -e '/^Cflags:/s/libdir/includedir/' \
	    	${WRKSRC}/libxml++-2.6.pc.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/(docs|examples)//g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
