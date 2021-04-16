# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME?=	victoria-metrics
DISTVERSIONPREFIX=	v
DISTVERSION=	1.58.0
CATEGORIES=	net-mgmt

MAINTAINER=	danfe@FreeBSD.org
COMMENT?=	Fast, cost-effective, and scalable time series database

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules,no_targets
USE_RC_SUBR?=	${PORTNAME}
MAKE_ENV=	PKG_TAG=${DISTVERSIONPREFIX}${DISTVERSION} \
		BUILDINFO_TAG=edd1590 GOOS=${OPSYS:tl}
ALL_TARGET=	${PORTNAME}-pure

USE_GITHUB=	yes
GH_ACCOUNT=	VictoriaMetrics
GH_PROJECT=	VictoriaMetrics

USERS=		victoria-metrics
GROUPS=		victoria-metrics
VICTORIA_DATA?=	/var/db/victoria-metrics

SUB_LIST+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_USER=${USERS}

PLIST_SUB+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_GROUP=${GROUPS} \
		VICTORIA_USER=${USERS}

OPTIONS_DEFINE=	DOCS

.if !target(do-install)
do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/bin/${PORTNAME}-pure \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${VICTORIA_DATA}
.endif

.if !target(do-install-DOCS-on)
do-install-DOCS-on:
	@cd ${INSTALL_WRKSRC}/docs && ${RM} robots.txt vm*
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

.include "${MASTERDIR}/Makefile.deps"
