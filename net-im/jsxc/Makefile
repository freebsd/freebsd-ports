PORTNAME=	jsxc
DISTVERSION=	4.4.0
CATEGORIES=	net-im www
MASTER_SITES=	https://github.com/jsxc/jsxc/releases/download/v${DISTVERSION}/

MAINTAINER=	mdw@FreeBSD.org
COMMENT=	Browser-based XMPP Client
WWW=		https://www.jsxc.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

post-install:
	${FIND} -s ${STAGEDIR}${WWWDIR} -not -type d | ${SORT} | \
		${SED} -e 's#^${STAGEDIR}${PREFIX}/##'  >> ${TMPPLIST}

.include <bsd.port.mk>
