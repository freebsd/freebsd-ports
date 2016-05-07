# $FreeBSD$

PORTNAME=	alt-ergo
PORTVERSION=	2015
CATEGORIES=	math
MASTER_SITES=	http://downloads.dragonlace.net/src/
PKGNAMESUFFIX=	-spark
DISTNAME=	alt-ergo-for-spark-gpl-${PORTVERSION}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Automatic solver for SPARK 2015

LICENSE=	CeCILL-C
LICENSE_NAME=	Ce[a] C[nrs] I[nria] L[ogiciel] L[ibre] C license, version 1
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	ocaml-zarith>1.2:math/ocaml-zarith \
		ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph
RUN_DEPENDS=	ocaml-ocamlgraph>1.8:math/ocaml-ocamlgraph

USES=		gmake
USE_OCAML=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	NAME=alt-ergo-spark
PLIST_FILES=	bin/alt-ergo-spark man/man1/alt-ergo-spark.1.gz

post-install:
	${MV} ${STAGEDIR}${MANPREFIX}/man/man1/alt-ergo.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/alt-ergo-spark.1.gz

.include <bsd.port.mk>
