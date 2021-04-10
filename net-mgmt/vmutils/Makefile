# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>

PORTNAME=	vmutils
DISTVERSIONPREFIX=	v
DISTVERSION=	1.58.0
CATEGORIES=	net-mgmt
DISTINFO_FILE=	${.CURDIR}/../victoria-metrics/distinfo

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Ancillary utilities and agent for VictoriaMetrics

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake go:modules,no_targets
USE_RC_SUBR=	vmagent
MAKE_ENV=	PKG_TAG=${DISTVERSIONPREFIX}${DISTVERSION} \
		BUILDINFO_TAG=edd1590 GOOS=${OPSYS:tl}
ALL_TARGET=	${PORTNAME}-pure

USE_GITHUB=	yes
GH_ACCOUNT=	VictoriaMetrics
GH_PROJECT=	VictoriaMetrics

.include "${.CURDIR}/../victoria-metrics/Makefile.deps"

USERS=		victoria-metrics
GROUPS=		victoria-metrics
VICTORIA_DATA?=	/var/db/victoria-metrics

SUB_LIST+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_USER=${USERS}

PLIST_SUB+=	VICTORIA_DATA=${VICTORIA_DATA} \
		VICTORIA_GROUP=${GROUPS} \
		VICTORIA_USER=${USERS}

OPTIONS_DEFINE=	DOCS

do-install:
.for p in agent alert auth backup ctl restore
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vm${p}-pure \
		${STAGEDIR}${PREFIX}/bin/vm${p}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/docs/vm* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
