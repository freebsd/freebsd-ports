PORTNAME=	check_syncthing
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
CATEGORIES=	net-mgmt

MAINTAINER=	dsh@bamus.cz
COMMENT=	Icinga2 monitoring plugin for syncthing daemon
WWW=		https://github.com/dsh2dsh/check_syncthing

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	dsh2dsh

GO_MOD_DIST=	github
GO_MODULE=	github.com/dsh2dsh/${PORTNAME}
_BUILD_XFLAGS=	main.version=${DISTVERSIONFULL}
GO_BUILDFLAGS=	-ldflags "${STRIP} ${_BUILD_XFLAGS:S!^!-X ${GO_MODULE}/!}"

PLIST_FILES=	libexec/nagios/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
