# Ports collection makefile for:  bro
# Date created:			  Sat Feb 28, 1998
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	bro
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.bro-ids.org/downloads/archive/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	System for detecting Network Intruders in real-time

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	GeoIP:${PORTSDIR}/net/GeoIP

USE_CMAKE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}

OPTIONS_DEFINE=	IPV6 LBL_HF LBL_CF ASSERT
OPTIONS_DEFAULT=	LBL_HF LBL_CF
LBL_HF_DESC=	Address to hostname filter support
LBL_CF_DESC=	Unix time to formated time/date filter support
OPTIONS_EXCLUDE=NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CMAKE_ARGS+=	-DBROv6:BOOL=ON
.endif

.if ${PORT_OPTIONS:MLBL_HF}
RUN_DEPENDS+=	hf:${PORTSDIR}/sysutils/lbl-hf
.endif

.if ${PORT_OPTIONS:MLBL_CF}
RUN_DEPENDS+=	cf:${PORTSDIR}/sysutils/lbl-cf
.endif

.if ${PORT_OPTIONS:MASSERT}
CMAKE_ARGS+=	-DENABLE_DEBUG:BOOL=ON
.endif

.include <bsd.port.mk>
