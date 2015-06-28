# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	why3
PORTVERSION=	0.83
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://gforge.inria.fr/frs/download.php/33490/ \
		http://pkgs.fedoraproject.org/repo/pkgs/why3/${FEDORA}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Deductive program verification platform

LICENSE=	LGPL21

CONFLICT_INSTALL= why3-gpl-*

BUILD_DEPENDS=	ocaml-zarith>1.2:${PORTSDIR}/math/ocaml-zarith \
		lablgtk2:${PORTSDIR}/x11-toolkits/ocaml-lablgtk2 \
		ocaml-sqlite3>2:${PORTSDIR}/databases/ocaml-sqlite3 \
		ocaml-ocamlgraph>1.8:${PORTSDIR}/math/ocaml-ocamlgraph \
		camlp5o:${PORTSDIR}/devel/ocaml-camlp5

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
#DOCS_BUILD_DEPENDS=		rubber:${PORTSDIR}/textproc/rubber \
#				hevea:${PORTSDIR}/textproc/hevea

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/src/util/sysutil.ml \
		${WRKSRC}/src/jessie/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/manual.pdf ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
