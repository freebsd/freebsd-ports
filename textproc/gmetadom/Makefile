# Created by: ijliao
# $FreeBSD$

PORTNAME=	gmetadom
PORTVERSION=	0.2.6
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Collection of DOM Implementations

LIB_DEPENDS=	libgdome.so:textproc/gdome2

USES=		compiler:c++11-lang gmake gnome iconv libtool localbase \
		pathfix pkgconfig
USE_GNOME=	glib20 libxml2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	OCAML
OPTIONS_SUB=	yes

OCAML_DESC=	OCAML language support

OCAML_BUILD_DEPENDS=	ocamlfind:devel/ocaml-findlib \
			ocamlc:lang/ocaml
OCAML_CONFIGURE_OFF=	HAVE_OCAMLDEP=no HAVE_OCAMLFIND=no HAVE_OCAMLOPT=no

post-patch:
	@${REINPLACE_CMD} -e 's/-lstdc++//g' \
		${WRKSRC}/src/gdome_cpp_smart/Makefile.in \
		${WRKSRC}/src/gdome_cpp_smart/test/Makefile.in

.include <bsd.port.mk>
