# Created by: ijliao
# $FreeBSD$

PORTNAME=	gmetadom
PORTVERSION=	0.2.6
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of DOM Implementations

LIB_DEPENDS=	libgdome.so:${PORTSDIR}/textproc/gdome2

USES=		pathfix pkgconfig gmake
USE_GNOME=	glib20 libxml2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
USE_LDCONFIG=	yes

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

post-patch:
	@${REINPLACE_CMD} -e 's/-lstdc++//g' ${WRKSRC}/src/gdome_cpp_smart/Makefile.in

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
