# New ports collection makefile for:    zh-dvipdfm-cjk
# Date created:		8 March 2001
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	dvipdfm
PORTVERSION=	20020605
CATEGORIES=	print
MASTER_SITES=	http://project.ktug.or.kr/dvipdfm-cjk/snapshot/ \
		http://project.ktug.or.kr/dvipdfmx/snapshot/
PKGNAMESUFFIX=	-cjk
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	statue@freebsd.sinica.edu.tw

BUILD_DEPENDS=	${LOCALBASE}/lib/libkpathsea.a:${PORTSDIR}/print/teTeX
LIB_DEPENDS=	png:${PORTSDIR}/graphics/png

MAN1=		dvipdfm.1

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
