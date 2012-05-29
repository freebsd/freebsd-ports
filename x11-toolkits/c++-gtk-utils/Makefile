# New ports collection makefile for:	c++-gtk-utils
# Date created:		2011-12-23
# Whom:			Pawel Pekala <pawel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	c++-gtk-utils
PORTVERSION=	2.0.9
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/cxx-gtk-utils/cxx-gtk-utils/${PORTVERSION}/
DISTNAME=	c%2B%2B-gtk-utils-${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Lightweight library for programming GTK+ programs

LICENSE=	LGPL21

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_GCC=	4.4+
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_ARGS+=--docdir=${DOCSDIR}

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=--enable-debug
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/pkgconfig|(prefix)/libdata/pkgconfig|' \
		${REINPLACE_FILE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 1000000
USE_AUTOTOOLS=	autoconf aclocal libtool
ACLOCAL_ARGS=	-I${LOCALBASE}/share/aclocal
REINPLACE_FILE=	${WRKSRC}/Makefile.am

pre-configure:
	@cd ${WRKSRC} && ./bootstrap-gtk2.sh

.else
CONFIGURE_SCRIPT=	configure-gtk2
REINPLACE_FILE=		${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
