# New ports collection makefile for:	fpc-libxml2
# Date created:		2010-04-22
# Whom:			Christoper Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	textproc lang
PKGNAMESUFFIX=	-libxml2

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Interface to xml2 library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//:S/2//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBXML2	"Install xml2 library"	on

.include "${MASTERDIR}/Makefile"
