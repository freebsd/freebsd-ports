# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	net lang
PKGNAMESUFFIX=	-pcap

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal unit for libpcap library

USE_FPC=	rtl-extra

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBPCAP
LIBPCAP_DESC=	Install ubiquitous network traffic capture library
OPTIONS_DEFAULT=	LIBPCAP

LIBPCAP_LIB_DEPENDS=	libpcap.so:net/libpcap

.include "${MASTERDIR}/Makefile"
