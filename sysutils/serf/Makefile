PORTNAME=	serf
PORTVERSION=	0.10.1
PORTREVISION=	4
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils
PKGNAMEPREFIX=	hashicorp-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Service discovery and configuration made easy
WWW=		https://serfdom.io/

LICENSE=	MPL20

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	hashicorp
GH_TUPLE=	golang:net:v0.8.0:net \
		golang:sys:v0.6.0:sys

GO_MODULE=	github.com/hashicorp/serf
GO_TARGET=	./cmd/${PORTNAME}

USE_RC_SUBR=	serf

USERS=		serf
GROUPS=		serf

PLIST_FILES=	bin/serf

pre-patch:
.for m in net sys
	${RM} -r ${WRKSRC}/vendor/golang.org/x/$m
	${LN} -s ${WRKDIR}/$m-* ${WRKSRC}/vendor/golang.org/x/$m
.endfor
	${RM} ${WRKSRC}/vendor/modules.txt

.include <bsd.port.mk>
