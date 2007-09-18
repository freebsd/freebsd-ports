# New ports collection makefile for:	fpc-httpd
# Date created: 			2007-09-11
# Whom: 				Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	www lang
PKGNAMESUFFIX=	-httpd

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal httpd unit

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/base/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	APACHE13	"Install apache13 server "	off \
		APACHE20	"Install apache20 server"	off \
		APACHE22	"Install apache22 server"	off

.include "${MASTERDIR}/Makefile"
