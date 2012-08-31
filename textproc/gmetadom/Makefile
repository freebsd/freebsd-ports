# ex:ts=8
# Ports collection makefile for:	gmetadom
# Date created:			Jul 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gmetadom
PORTVERSION=	0.2.6
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Collection of DOM Implementations

LIB_DEPENDS=	gdome:${PORTSDIR}/textproc/gdome2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_GNOME=	glib20 gnomehack libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes

OPTIONS_DEFINE=	OCAML

OCAML_DESC=	OCAML language support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOCAML}
BUILD_DEPENDS+=	ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
		ocamlc:${PORTSDIR}/lang/ocaml
PLIST_SUB+=	OCAML=""
.else
CONFIGURE_ARGS+=	HAVE_OCAMLDEP=no HAVE_OCAMLFIND=no HAVE_OCAMLOPT=no
PLIST_SUB+=	OCAML="@comment "
.endif

# Shim to clean-up a previous bad install - this can be removed
# PORTVERSION > 0.2.6 along with the associated pkg-plist @exec
# entries.
pre-install:
	@if [ -d ${LOCALBASE}/lib/ocaml/gdome2 ]; then \
		${RM} -f ${LOCALBASE}/lib/ocaml/gdome2/* 2>/dev/null && \
		${RMDIR} ${LOCALBASE}/lib/ocaml/gdome2 2>/dev/null; \
	fi
	@if [ -f ${LOCALBASE}/lib/ocaml/stublibs/dllmlgdome.so ]; then \
		${RM} -f ${LOCALBASE}/lib/ocaml/stublibs/dllmlgdome.so 2>/dev/null; \
	fi
	@if [ -f ${LOCALBASE}/lib/ocaml/stublibs/dllmlgdome.so.owner ]; then \
		${RM} -f ${LOCALBASE}/lib/ocaml/stublibs/dllmlgdome.so.owner 2>/dev/null; \
	fi

.include <bsd.port.mk>
