# $FreeBSD$

PORTNAME=	keybase
PORTVERSION=	0.7.8
CATEGORIES=	security
MASTER_SITES=	https://dist.keybase.io/pkg/files/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Keybase.io client

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg \
		${LOCALBASE}/bin/node:${PORTSDIR}/www/node

NO_ARCH=	yes
NO_BUILD=	yes
USES=		tar:tgz

SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/package

# Install it to a private place instead of polluting lib/node_modules
# which npm(1) owns and will upgrade beneath pkg(8) control.
KEYBASE_PREFIX=	${PREFIX}/libexec/${PORTNAME}

add-plist-post: npm-auto-plist

npm-auto-plist:
	@{ \
	  ${ECHO_CMD} "bin/${PORTNAME}"; \
	  ${FIND} ${STAGEDIR}${KEYBASE_PREFIX} -type f -or -type l; \
	} | ${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}

do-install:
	@${MKDIR} ${WRKDIR}/tmp ${STAGEDIR}${KEYBASE_PREFIX}/lib
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${KEYBASE_PREFIX}/lib/node_modules/${PORTNAME})
	${CHMOD} +x ${STAGEDIR}${KEYBASE_PREFIX}/lib/node_modules/${PORTNAME}/bin/main.js
	${LN} -s ${KEYBASE_PREFIX}/lib/node_modules/${PORTNAME}/bin/main.js ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

# Quiet stage-qa
post-install:
	@${RM} ${STAGEDIR}${KEYBASE_PREFIX}/lib/node_modules/keybase/node_modules/request/node_modules/node-uuid/benchmark/bench.sh

.include <bsd.port.mk>
