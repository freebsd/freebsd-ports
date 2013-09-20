# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	www lang
PKGNAMESUFFIX=	-httpd22

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal httpd unit

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	APACHE22
APACHE22_DESC=	Install apache22 server

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
