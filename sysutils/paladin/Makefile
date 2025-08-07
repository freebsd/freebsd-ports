PORTNAME=	paladin
PORTVERSION=	2.0.1
PORTREVISION=	29
CATEGORIES=	sysutils

MAINTAINER=	rwestlun@gmail.com
COMMENT=	Simple process supervisor
WWW=		https://github.com/rwestlund/paladin

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-X main.localbase=${PREFIX}"

USE_GITHUB=	yes
GH_ACCOUNT=	rwestlund
GH_TUPLE=	golang:sys:v0.5.0:sys/vendor/golang.org/x/sys_

pre-patch:
	${RM} -r ${WRKSRC}/vendor/golang.org/x/sys
	${MV} ${WRKSRC}/vendor/golang.org/x/sys_ ${WRKSRC}/vendor/golang.org/x/sys

post-install:
	@${CP} ${WRKSRC}/etc/paladin.conf.sample ${STAGEDIR}/${LOCALBASE}/etc/
	@${CP} ${WRKSRC}/etc/rc.d/paladin ${STAGEDIR}/${LOCALBASE}/etc/rc.d/

.include <bsd.port.mk>
