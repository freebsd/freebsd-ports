# ex:ts=8
# Ports collection makefile for:	gmetadom
# Date created:			Jul 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gmetadom
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}b

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Collection of DOM Implementations

BUILD_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config
LIB_DEPENDS=	gdome.8:${PORTSDIR}/textproc/gdome2
RUN_DEPENDS=	pkg-config:${PORTSDIR}/devel/pkg-config

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GNOME=	glib20 gnomehack libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

OPTIONS=	OCAML "OCAML language support" off

.include <bsd.port.pre.mk>

.if defined(WITH_OCAML)
BUILD_DEPENDS+=	ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		ocamlc:${PORTSDIR}/lang/ocaml
PLIST_SUB+=	WITH_OCAML=""
.else
PLIST_SUB+=	WITH_OCAML="@comment "
.endif

.include <bsd.port.post.mk>
