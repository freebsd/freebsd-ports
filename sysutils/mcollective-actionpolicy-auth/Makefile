# $FreeBSD$

PORTNAME=	mcollective-actionpolicy-auth
PORTVERSION=	2.1.0
CATEGORIES=	sysutils

MAINTAINER=	romain@FreeBSD.org
COMMENT=	MCollective Authorization plugin allowing fine grained ACLs

LICENSE=	APACHE20

RUN_DEPENDS=	mcollective>=2:sysutils/mcollective

USE_GITHUB=	yes
GH_ACCOUNT=	puppetlabs
SUB_FILES=	pkg-message

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	share/mcollective/util/actionpolicy.ddl \
		share/mcollective/util/actionpolicy.rb
PLIST_DIRS=	etc/mcollective/policies

.if !target(do-install)
do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "util" ${STAGEDIR}${PREFIX}/share/mcollective
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mcollective/policies
.endif

.include <bsd.port.mk>
