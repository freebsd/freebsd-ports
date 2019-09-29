# $FreeBSD$

PORTNAME=	paladin
PORTVERSION=	2.0.1
CATEGORIES=	sysutils

MAINTAINER=	rwestlun@gmail.com
COMMENT=	Simple process supervisor

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X main.localbase=/usr/local"

USE_GITHUB=	yes
GH_ACCOUNT=	rwestlund

post-install:
	@${CP} ${WRKSRC}/etc/paladin.conf.sample ${STAGEDIR}/${LOCALBASE}/etc/
	@${CP} ${WRKSRC}/etc/rc.d/paladin ${STAGEDIR}/${LOCALBASE}/etc/rc.d/

.include <bsd.port.mk>
