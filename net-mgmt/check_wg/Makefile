PORTNAME=	check_wg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.8
CATEGORIES=	net-mgmt

MAINTAINER=	dsh@bamus.cz
COMMENT=	Icinga2 health check of wireguard peers, using output of wg(8)
WWW=		https://github.com/dsh2dsh/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.25,modules

USE_GITHUB=	yes
GH_ACCOUNT=	dsh2dsh

GO_MOD_DIST=	github
GO_MODULE=	github.com/${GH_ACCOUNT}/${PORTNAME}
_BUILD_XFLAGS=	main.version=${DISTVERSIONFULL}
GO_BUILDFLAGS=	-ldflags "${STRIP} ${_BUILD_XFLAGS:S!^!-X ${GO_MODULE}/!}"

PLIST_FILES=	libexec/nagios/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
