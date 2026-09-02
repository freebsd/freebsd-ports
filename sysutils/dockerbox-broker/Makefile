PORTNAME=	dockerbox-broker
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	sysutils

MAINTAINER=	leafoliage@FreeBSD.org
COMMENT=	Port forwarding daemon for dockerbox
WWW=		https://github.com/leafoliage/dockerbox-broker

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USES=		go:1.25+,modules
USE_GITHUB=	nodefault
GH_ACCOUNT=	leafoliage
GH_PROJECT=	dockerbox-broker

GO_MODULE=	github.com/leafoliage/dockerbox-broker
GO_TARGET=	.:${PREFIX}/sbin/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/.env.sample \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.env.sample
	${INSTALL_DATA} -m 0755 ${WRKSRC}/rc.d/${PORTNAME} \
		${STAGEDIR}${PREFIX}/etc/rc.d/${PORTNAME}

.include <bsd.port.mk>
