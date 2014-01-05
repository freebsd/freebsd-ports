# Created by: Craig Boston <craig@yekse.gank.org>
# $FreeBSD$

PORTNAME=	vde
PORTVERSION=	1.5.7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/OldFiles
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-mode virtual ethernet infrastructure

LICENSE=	GPLv2

CONFLICTS=	vde2-[0-9]*

MAKE_ARGS=	CC="${CC}"
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
USES=		gmake

CFLAGS+=	-fPIC

.include <bsd.port.mk>
