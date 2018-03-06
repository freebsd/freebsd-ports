# $FreeBSD$

PORTNAME=	blackbox_exporter
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.0
CATEGORIES=	sysutils

MAINTAINER=	fabian.freyer@physik.tu-berlin.de
COMMENT=	Blackbox prober for prometheus

LICENSE=	APACHE20

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus
USE_RC_SUBR=	blackbox_exporter
SUB_FILES=	pkg-message
SUB_LIST=	GH_TAGNAME=${GH_TAGNAME}

USERS=		prometheus
GROUPS=		prometheus

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	github.com/${GH_ACCOUNT}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/blackbox_exporter ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${GO_WRKSRC}/example.yml ${STAGEDIR}${PREFIX}/etc/blackbox_exporter.yml.sample

.include <bsd.port.mk>
