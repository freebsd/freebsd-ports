# Created by: Carlo Strub <cs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bapu
PORTVERSION=	0.3.0
CATEGORIES=	net
MASTER_SITES=	https://bitbucket.org/carlostrub/bapu/get/
PKGNAMEPREFIX=	go-
DISTNAME=	v${PORTVERSION}
DIST_SUBDIR=	go-bapu

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Virtual Machine Controller for Gandi.net

LICENSE=	BSD3CLAUSE

USES=		go tar:bzip2
GO_PKGNAME=	bitbucket.org/carlostrub/bapu
WRKSRC=		${WRKDIR}/carlostrub-bapu-23ca6b019fbc

post-install:
	${CP} -R ${WRKSRC}/bapu.toml.sample ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
