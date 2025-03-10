PORTNAME=	check_wg
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.7
PORTREVISION=	2
CATEGORIES=	net-mgmt

MAINTAINER=	dsh@bamus.cz
COMMENT=	Icinga2 health check of wireguard peers, using output of wg(8)
WWW=		https://github.com/dsh2dsh/${PORTNAME}

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:1.22,modules

GO_MODULE=	github.com/dsh2dsh/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="${STRIP} -w -X ${GO_MODULE}/main.version=${DISTVERSIONFULL}"

PLIST_FILES=	libexec/nagios/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/libexec/nagios/

.include <bsd.port.mk>
