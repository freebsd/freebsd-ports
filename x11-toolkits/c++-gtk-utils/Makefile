# New ports collection makefile for:	c++-gtk-utils
# Date created:		2011-12-23
# Whom:			Pawel Pekala <pawel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c++-gtk-utils
PORTVERSION=	2.0.4
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/cxx-gtk-utils/cxx-gtk-utils/${PORTVERSION}/
DISTNAME=	c%2B%2B-gtk-utils-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Lightweight library for programming GTK+ programs

LICENSE=	LGPL21

BUILD_DEPENDS=	chrpath:${PORTSDIR}/devel/chrpath
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=configure-gtk2
USE_GCC=	4.4+
USE_GNOME=	gtk20 gnomehack
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS+=--docdir=${DOCSDIR}

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|c++-gtk-utils po docs|c++-gtk-utils po|' \
		-e 's|install-pkgconfigDATA install-pkgdocDATA|install-pkgconfigDATA|' \
		${WRKSRC}/Makefile.in
.endif

post-install:
	@chrpath -d ${PREFIX}/lib/libcxx-gtk-utils-2-2.0.so.0

.include <bsd.port.mk>
