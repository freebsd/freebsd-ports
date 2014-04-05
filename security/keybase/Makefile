# $FreeBSD$

PORTNAME=	keybase
PORTVERSION=	0.2.18
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	https://dist.keybase.io/pkg/files/ \
		LOCAL/bdrewery/${PORTNAME}/:DEFAULT,deps \
		http://mirror.shatow.net/freebsd/${PORTNAME}/:DEFAULT,deps
EXTRACT_SUFX=	.tgz

MAINTAINER=	bdrewery@freebsd.org
COMMENT=	Keybase.io client

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	node>=0:${PORTSDIR}/www/node \
		gpg:${PORTSDIR}/security/gnupg

WRKSRC=		${WRKDIR}/package
NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

# Install it a private place instead of polluting lib/node_modules
# which npm(1) owns and will upgrade beneath pkg(8) control.
KEYBASE_PREFIX=	${PREFIX}/libexec/${PORTNAME}

add-plist-post: npm-auto-plist

npm-auto-plist:
	@{ \
	  ${ECHO_CMD} "bin/${PORTNAME}"; \
	  ${FIND} ${STAGEDIR}${KEYBASE_PREFIX} -type f -or -type l; \
	  ${FIND} ${STAGEDIR}${KEYBASE_PREFIX} -type d -d | ${SED} -e 's,^,@dirrm ,'; \
	} | ${SED} 's,${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}

do-install:
	@${MKDIR} ${WRKDIR}/tmp ${STAGEDIR}${KEYBASE_PREFIX}/lib
	(cd ${WRKSRC} &&	\
	    ${COPYTREE_SHARE} \* \
	    ${STAGEDIR}${KEYBASE_PREFIX}/lib/node_modules/${PORTNAME})
	${CHMOD} +x ${STAGEDIR}${KEYBASE_PREFIX}/lib/node_modules/${PORTNAME}/bin/main.js
	${LN} -s ${KEYBASE_PREFIX}/lib/node_modules/${PORTNAME}/bin/main.js \
	  ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

# Quiet stage-qa
post-install:
	@${RM} ${STAGEDIR}${KEYBASE_PREFIX}/lib/node_modules/keybase/node_modules/request/node_modules/node-uuid/benchmark/bench.sh

.include <bsd.port.mk>
