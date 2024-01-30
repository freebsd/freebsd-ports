PORTNAME=	typetools
PORTVERSION=	2.110
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.lcdf.org/type/
DISTNAME=	lcdf-${PORTNAME}-${PORTVERSION}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Tools for manipulating fonts
WWW=		https://www.lcdf.org/type/ #typetools

LICENSE=	GPLv2

USES=		tex
USE_TEX=	kpathsea

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-kpathsea=${LOCALBASE}

DATADIR=	${PREFIX}/share/lcdf-${PORTNAME}

CONFLICTS_INSTALL=	texlive-base

.include <bsd.port.mk>
