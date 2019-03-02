# $FreeBSD$

PORTNAME=	paladin
PORTVERSION=	2.0.0
CATEGORIES=	sysutils

MAINTAINER=	rwestlun@gmail.com
COMMENT=	Simple process supervisor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	rwestlund

# Override default build command to pass ldflags.
do-build:
	@(cd ${GO_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GO_ENV} ${GO_CMD} install \
		-ldflags="-X main.localbase=/usr/local" -v ${GO_TARGET})

post-install:
	@${CP} ${WRKSRC}/etc/paladin.conf.sample ${STAGEDIR}/${LOCALBASE}/etc/
	@${CP} ${WRKSRC}/etc/rc.d/paladin ${STAGEDIR}/${LOCALBASE}/etc/rc.d/

.include <bsd.port.mk>
