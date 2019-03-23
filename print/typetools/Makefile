# Created by: ijliao
# $FreeBSD$

PORTNAME=	typetools
PORTVERSION=	2.108
CATEGORIES=	print
MASTER_SITES=	http://www.lcdf.org/type/
DISTNAME=	lcdf-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools for manipulating fonts

LICENSE=	GPLv2

USE_TEX=	kpathsea

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kpathsea=${LOCALBASE}

DATADIR=	${PREFIX}/share/lcdf-${PORTNAME}

CONFLICTS_INSTALL=	texlive-base-[0-9]*

.include <bsd.port.mk>
