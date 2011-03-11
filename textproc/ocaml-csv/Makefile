# New ports collection makefile for:	ocaml-calendar
# Date created:				Feb 26, 2007
# Whom:					Jaap Boender <jaapb@kerguelen.org>
#
# $FreeBSD$
#

PORTNAME=	ocaml-csv
PORTVERSION=	1.2.1
CATEGORIES=	textproc
MASTER_SITES=	https://forge.ocamlcore.org/frs/download.php/420/

MAINTAINER=	tcrimi@gmail.com
COMMENT=	An OCaml library to read and write CSV files

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/extlib:${PORTSDIR}/devel/ocaml-extlib

WRKSRC=		${WRKDIR}/csv-${PORTVERSION}
USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
OCAML_PKGDIRS=	csv

.include <bsd.port.mk>
