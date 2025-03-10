PORTNAME=	check_syncthing
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.6
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	dsh@bamus.cz
COMMENT=	Icinga2 monitoring plugin for syncthing daemon
WWW=		https://github.com/dsh2dsh/check_syncthing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

USE_GITHUB=	yes
GH_ACCOUNT=	dsh2dsh

GO_MODULE=	github.com/dsh2dsh/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="${STRIP} -w -X ${GO_MODULE}/main.version=${DISTVERSIONFULL}"

PLIST_FILES=	libexec/nagios/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
