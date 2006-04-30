# ex:ts=8
# New ports collection makefile for:	libxml++
# Date created:			Feb 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/textproc/libxml++26/Makefile,v 1.13 2006/04/13 07:52:38 bland Exp $
#

PORTNAME=	libxml++
PORTVERSION=	2.14.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	bland@FreeBSD.org
COMMENT=	XML API for C++

LIB_DEPENDS=	glibmm-2.4.1:${PORTSDIR}/devel/glibmm
BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

LATEST_LINK=	libxml++26

USE_GMAKE=	yes
USE_GCC=	3.4
USE_GNOME=	gnomehack gnometarget libxml2 pkgconfig
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION="2.6" API_VERSION="2.6" DOC_VERSION=${PORTVERSION:R}

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/examples//' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/^gentoo_ltmain_version=/s/`.*`/$$gentoo_lt_version/' \
		${WRKSRC}/configure
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/(docs|examples)//g' ${WRKSRC}/Makefile.in
.endif

.if !defined(NOPORTDOCS)
post-configure:
	@${TOUCH} ${WRKSRC}/docs/reference/${PORTVERSION:R}/html/index.html
.endif

.include <bsd.port.mk>
