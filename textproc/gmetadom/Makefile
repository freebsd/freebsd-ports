# ex:ts=8
# Ports collection makefile for:	gmetadom
# Date created:			Jul 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gmetadom
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	A Collection of DOM Implementations

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig
LIB_DEPENDS=	gdome.8:${PORTSDIR}/textproc/gdome2
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkgconfig

.if defined(WITH_OCAML)
BUILD_DEPENDS+=	ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		ocamlc:${PORTSDIR}/lang/ocaml
PLIST_SUB+=	WITH_OCAML=""
.else
PLIST_SUB+=	WITH_OCAML="@comment "
.endif

USE_GNOME=	glib20 gnomehack libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
