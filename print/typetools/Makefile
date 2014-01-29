# Created by: ijliao
# $FreeBSD$

PORTNAME=	typetools
PORTVERSION=	2.100
CATEGORIES=	print
MASTER_SITES=	http://www.lcdf.org/type/
DISTNAME=	lcdf-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for manipulating fonts

LICENSE=	GPLv2

USE_TEX=	base
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_kpathsea_kpathsea_h=yes
CONFIGURE_ARGS=	--with-kpathsea=${LOCALBASE}

DATADIR=	${PREFIX}/share/lcdf-${PORTNAME}

.include <bsd.port.mk>
