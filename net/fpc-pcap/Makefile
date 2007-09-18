# New ports collection makefile for:	fpc-pcap
# Date created:		2006-09-11
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	net lang
PKGNAMESUFFIX=	-pcap

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal unit for libpcap library

BUILD_DEPENDS=	ppc386:${PORTSDIR}/lang/fpc

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/extra/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBPCAP	"Install ubiquitous network traffic capture library"	on

.include "${MASTERDIR}/Makefile"
