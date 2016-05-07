# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	why3
PORTVERSION=	0.83
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/33490/ \
		http://pkgs.fedoraproject.org/repo/pkgs/why3/${FEDORA}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Deductive program verification platform

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL= why3-gpl-*

BUILD_DEPENDS=	ocaml-zarith>1.2:math/ocaml-zarith \
		lablgtk2:x11-toolkits/ocaml-lablgtk2 \
		ocaml-sqlite3>2:databases/ocaml-sqlite3 \
		ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph \
		camlp5o:devel/ocaml-camlp5

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-all

USES=		gmake
USE_OCAML=	yes

FEDORA=		${DISTNAME}${EXTRACT_SUFX}/35f99e5f64939e50ea57f641ba2073ec
ALL_TARGET=	all byte

CONFIGURE_ARGS=	--enable-relocation \
		--disable-doc \
		--disable-pvs-libs \
		--disable-profiling \
		--disable-coq-tactic \
		--disable-coq-libs \
		--disable-isabelle-libs

OPTIONS_DEFINE=	DOCS

# The pdf is pre-built, but the makefile wants to build it again in order
# to generate manual.bbl which is used to build the html documention.
# Regenerating pdf fails, and the dependencies are heavy.  Disable this
# all for now and just manually install the pdf.  The "doc" target was
# also removed from ALL_TARGET
#
#DOCS_CONFIGURE_ENABLE=		doc
#DOCS_BUILD_DEPENDS=		rubber:textproc/rubber \
#				hevea:textproc/hevea

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/src/util/sysutil.ml \
		${WRKSRC}/src/jessie/Makefile.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/why3* \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/why3/*.o \
		${STAGEDIR}${PREFIX}/lib/why3/plugins/*.cmxs \
		${STAGEDIR}${PREFIX}/lib/why3/why3-cpulimit

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
