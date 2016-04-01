# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	why3
PORTVERSION=	2015
CATEGORIES=	math
MASTER_SITES=	http://downloads.dragonlace.net/src/ \
		LOCAL/marino
PKGNAMESUFFIX=	-spark
DISTNAME=	why3-for-spark-gpl-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Component of SPARK 2015

LICENSE=	LGPL21 GPLv3
LICENSE_COMB=	multi

BROKEN=		broken by recent updated to an ocaml dependency

BUILD_DEPENDS=	menhir:devel/menhir \
		ocaml-zip>1:archivers/ocaml-zip \
		ocaml-zarith>1.2:math/ocaml-zarith \
		lablgtk2:x11-toolkits/ocaml-lablgtk2 \
		ocaml-sqlite3>2:databases/ocaml-sqlite3 \
		ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph \
		camlp5o:devel/ocaml-camlp5

USES=		gmake
USE_OCAML=	yes
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
		-e 's|why3.el|why3-mode.el|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
