# Created by: Matthieu BOUTHORS <matthieu@labs.fr>
# $FreeBSD$

PORTNAME=	sslscan
PORTVERSION=	1.11.6
DISTVERSIONSUFFIX=	-${GH_ACCOUNT}
CATEGORIES=	security

MAINTAINER=	gavin@FreeBSD.org
COMMENT=	SSLScan is a fast SSL port scanner

LICENSE=	GPLv3

USES=		gmake
USE_OPENSSL=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	rbsec

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT:Mopenssl-devel}
BROKEN=		Does not build with openssl-devel
.endif

.include <bsd.port.post.mk>
