# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/net/uhttpmock/Makefile 19893 2014-09-20 07:46:54Z kwm $

PORTNAME=	uhttpmock
PORTVERSION=	0.4.0.180914
PORTREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	LOCAL/kwm
#https://gitorious.org/${GO_ACCOUNT}/${GO_PROJECT}/archive/${GO_TAGNAME}.tar.gz?dummy= \
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	HTTP web service mocking library for GNOME

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		vapigen:${PORTSDIR}/lang/vala-vapigen \
		gtkdoc-rebase:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libsoup-2.4.so:${PORTSDIR}/devel/libsoup

WRKSRC=		${WRKDIR}/uhttpmock-uhttpmock

USES=		gettext gmake libtool pathfix pkgconfig
USE_GNOME=	gnomehier gnomeprefix gtk20 introspection:build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALL_TARGET=	install-strip

GO_ACCOUNT=	uhttpmock
GO_PROJECT=	uhttpmock
GO_TAGNAME=	2d07f3819399300
FETCH_ARGS?=	-o ${DISTDIR}/${DISTFILES}

pre-configure:
		cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
