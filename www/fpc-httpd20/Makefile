# New ports collection makefile for:	fpc-httpd20
# Date created: 			2009-01-06
# Whom: 				Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	www lang
PKGNAMESUFFIX=	-httpd20

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal httpd unit

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	APACHE20	"Install apache20 server"	off

.include "${MASTERDIR}/Makefile"
