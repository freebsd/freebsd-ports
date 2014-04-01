# $FreeBSD$

PORTNAME=	couchpotato
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	GH

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	Automatic Movie Downloading via NZBs & Torrents

LICENSE=	GPLv3 PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	2.6+

USE_GITHUB=     yes
GH_ACCOUNT=     RuudBurger  
GH_PROJECT=     CouchPotatoServer
GH_COMMIT=      d023eb8
GH_TAGNAME=     ${GH_COMMIT}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

USERS=		media
GROUPS=		media

OPTIONS_DEFINE=	OPENSSL
OPTIONS_DEFAULT=	OPENSSL

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl
.endif

do-install:
	${INSTALL} -d ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/CouchPotatoServer
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/CouchPotatoServer

.include <bsd.port.post.mk>
