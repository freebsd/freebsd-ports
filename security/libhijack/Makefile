PORTNAME=	libhijack
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
CATEGORIES=	security

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Runtime process infection made easy
WWW=		https://git.hardenedbsd.org/SoldierX/libhijack

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		uidfix

ONLY_FOR_ARCHS=	aarch64 amd64
ONLY_FOR_ARCHS_REASON=	not ported to other architectures
BROKEN_aarch64=	does not build, upstream is working on a fix (PR 283408)
BROKEN_FreeBSD_13=	does not build, upstream is working on a fix (PR 283408)

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	SoldierX

USE_LDCONFIG=	yes

.include <bsd.port.mk>
