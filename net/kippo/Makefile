# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kippo
PORTVERSION=	0.9
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Medium interaction ssh honeypot

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	desaster

USES=		python twisted:run,conch,web
NO_BUILD=	yes

USE_RC_SUBR=	kippo

USERS=		kippo
GROUPS=		kippo

SUB_FILES=	pkg-message
SUB_LIST+=	PYTHON=${PYTHON_CMD}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for f in kippo.cfg.dist kippo.tac fs.pickle
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DATADIR}
.endfor
.for d in data doc honeyfs kippo txtcmds utils
	@${MKDIR} ${STAGEDIR}${DATADIR}/${d}
	@(cd ${WRKSRC}/${d}/ && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/${d})
.endfor

.include <bsd.port.mk>
