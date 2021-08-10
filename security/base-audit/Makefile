# Created by: Miroslav Lachman

PORTNAME=	base-audit
PORTVERSION=	0.5
CATEGORIES=	security
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	000.fbsd@quip.cz
COMMENT=	Daily periodic check of vulnerabilities in base system

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/sbin/pkg:${PKG_ORIGIN}

NO_ARCH=	yes
NO_BUILD=	yes
NO_INSTALL=	yes

SUB_FILES=	405.pkg-base-audit

PERIODIC_SECURITY=	etc/periodic/security

PLIST_FILES=	${PERIODIC_SECURITY}/405.pkg-base-audit

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${PERIODIC_SECURITY}
	 ${INSTALL_SCRIPT} ${WRKDIR}/405.pkg-base-audit \
		${STAGEDIR}${PREFIX}/${PERIODIC_SECURITY}

.include <bsd.port.mk>
