# $FreeBSD$

PORTNAME=	serf
PORTVERSION=	0.8.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	hashicorp-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Service discovery and configuration made easy

LICENSE=	MPL20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp

GO_TARGET=	./cmd/${PORTNAME}

USE_RC_SUBR=	serf

USERS=		serf
GROUPS=		serf

PLIST_FILES=	bin/serf

.include <bsd.port.mk>
