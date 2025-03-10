PORTNAME=	ocaml-csv
PORTVERSION=	1.2.1
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/420/

MAINTAINER=	tcrimi@gmail.com
COMMENT=	OCaml library to read and write CSV files
WWW=		https://forge.ocamlcore.org/projects/csv/

LICENSE=	LGPL21+

USES=		gmake ocaml:findlib
OCAML_PKGDIRS=	csv

WRKSRC=		${WRKDIR}/csv-${PORTVERSION}
MAKE_ARGS=	byte native
TEST_TARGET=	tests

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

.include <bsd.port.mk>
