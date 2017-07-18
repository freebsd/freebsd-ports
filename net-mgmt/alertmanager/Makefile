# Created by: Michal Hanula <michal@hanu.la>
# $FreeBSD$

PORTNAME=	alertmanager
PORTVERSION=	0.5.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt

MAINTAINER=	michal@hanu.la
COMMENT=	Alert routing for prometheus

LICENSE=	APACHE20

USES=		go gmake
USE_GITHUB=	yes
GH_ACCOUNT=	prometheus

GO_PKGNAME=	github.com/prometheus/${PORTNAME}

USE_RC_SUBR=	alertmanager

USERS=		alertmanager
GROUPS=		alertmanager

PLIST_FILES=	bin/alertmanager \
		etc/alertmanager/alertmanager.yml.sample

do-build:
	(cd ${GO_WRKSRC}/cmd/alertmanager ; ${SETENV} ${GO_ENV} go install)

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/alertmanager ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/alertmanager
	${INSTALL_DATA} ${WRKSRC}/doc/examples/simple.yml ${STAGEDIR}${PREFIX}/etc/alertmanager/alertmanager.yml.sample

.include <bsd.port.mk>
