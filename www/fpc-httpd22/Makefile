# New ports collection makefile for:	fpc-httpd22
# Date created: 			2009-01-06
# Whom: 				Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	www lang
PKGNAMESUFFIX=	-httpd22

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal httpd unit

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	APACHE22	"Install apache22 server"	off

.include "${MASTERDIR}/Makefile"
