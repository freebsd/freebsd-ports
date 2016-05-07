# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	ocaml-csv
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/420/

MAINTAINER=	tcrimi@gmail.com
COMMENT=	OCaml library to read and write CSV files

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/extlib:devel/ocaml-extlib

WRKSRC=		${WRKDIR}/csv-${PORTVERSION}
USES=		gmake
MAKE_ARGS=	byte native
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
OCAML_PKGDIRS=	csv

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
