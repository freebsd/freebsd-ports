# Created by: Athanasios Douitsis <aduitsis@cpan.org>
# $FreeBSD$

PORTNAME=	pushgateway
PORTVERSION=	0.3.1
PORTREVISION=	1
DISTVERSIONPREFIX=v
CATEGORIES=	net-mgmt

MAINTAINER=	aduitsis@cpan.org
COMMENT=	Prometheus push acceptor for ephemeral and batch jobs

LICENSE=	APACHE20

USES=		go gmake
GH_ACCOUNT=	prometheus
USE_GITHUB=	yes

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}

USE_RC_SUBR=	pushgateway

USERS=		prometheus
GROUPS=		prometheus

do-build:
	@(cd ${GO_WRKSRC} ; ${SETENV} ${MAKE_ENV} ${GO_ENV} go install)

do-install:
	${INSTALL_PROGRAM} ${GO_WRKDIR_BIN}/pushgateway ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DESTDIR}/var/db/${PORTNAME}

.include <bsd.port.mk>
