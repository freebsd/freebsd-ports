# Created by: ijliao
# $FreeBSD$

PORTNAME=	gmetadom
PORTVERSION=	0.2.6
PORTREVISION=	2
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
OPTIONS_SUB=	yes

OCAML_DESC=	OCAML language support

OCAML_BUILD_DEPENDS=	ocamlfind:${PORTSDIR}/devel/ocaml-findlib \
			ocamlc:${PORTSDIR}/lang/ocaml
OCAML_CONFIGURE_OFF=	HAVE_OCAMLDEP=no HAVE_OCAMLFIND=no HAVE_OCAMLOPT=no

post-patch:
	@${REINPLACE_CMD} -e 's/-lstdc++//g' ${WRKSRC}/src/gdome_cpp_smart/Makefile.in

.include <bsd.port.mk>
