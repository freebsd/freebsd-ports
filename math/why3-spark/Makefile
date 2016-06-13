# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	why3
PORTVERSION=	2016
CATEGORIES=	math
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMESUFFIX=	-spark
DISTNAME=	why3-for-spark-gpl-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Component of SPARK ${PORTVERSION}

LICENSE=	LGPL21 GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-zip>1:archivers/ocaml-zip \
		ocaml-zarith>1.2:math/ocaml-zarith \
		lablgtk2:x11-toolkits/ocaml-lablgtk2 \
		ocaml-sqlite3>2:databases/ocaml-sqlite3 \
		ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph \
		camlp5o:devel/ocaml-camlp5
LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gmake gettext
USE_OCAML=	yes
USE_GNOME=	gtk20 pango atk cairo gdkpixbuf2 glib20 gtksourceview2
ALL_TARGET=	all
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-all

MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--enable-relocation \
		--disable-doc \
		--disable-pvs-libs \
		--disable-profiling \
		--disable-coq-tactic \
		--disable-coq-libs \
		--disable-isabelle-libs

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/src/util/sysutil.ml
	@${REINPLACE_CMD} -e '/cp -f share\/Make/d' \
		-e '/gcc/d' ${WRKSRC}/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*why3
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/why3/why3server
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/why3/why3cpulimit
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/why3/commands/why3*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/why3/plugins/*.cmxs

.include <bsd.port.mk>
