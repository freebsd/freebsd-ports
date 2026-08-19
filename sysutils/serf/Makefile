PORTNAME=	serf
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.4
PORTREVISION=	3
CATEGORIES=	sysutils
PKGNAMEPREFIX=	hashicorp-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Service discovery and configuration made easy
WWW=		https://www.serf.io/

LICENSE=	MPL20

USES=		go:modules
USE_RC_SUBR=	serf

GO_MODULE=	github.com/hashicorp/serf
GO_TARGET=	./cmd/${PORTNAME}

USERS=		serf
GROUPS=		serf

PLIST_FILES=	bin/serf

.include <bsd.port.mk>
