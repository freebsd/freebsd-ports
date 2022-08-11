PORTNAME=	ocaml-csv
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/420/

MAINTAINER=	tcrimi@gmail.com
COMMENT=	OCaml library to read and write CSV files

LICENSE=	LGPL21+

WRKSRC=		${WRKDIR}/csv-${PORTVERSION}
USES=		gmake
MAKE_ARGS=	byte native
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
OCAML_PKGDIRS=	csv
TEST_TARGET=	tests

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
