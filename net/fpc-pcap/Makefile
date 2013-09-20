# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	net lang
PKGNAMESUFFIX=	-pcap

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit for libpcap library

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBPCAP
LIBPCAP_DESC=	Install ubiquitous network traffic capture library
OPTIONS_DEFAULT=	LIBPCAP

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
