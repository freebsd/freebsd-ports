# Created by: Frederic Culot <culot@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kippo
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	culot@FreeBSD.org
COMMENT=	Medium interaction ssh honeypot

LICENSE=	BSD

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pycrypto>0:${PORTSDIR}/security/py-pycrypto \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:${PORTSDIR}/devel/py-zope.interface
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USES=		twisted:run,conch,web
NO_BUILD=	yes

USE_RC_SUBR=	kippo

USERS=		kippo
GROUPS=		kippo

SUB_FILES=	pkg-message
SUB_LIST+=	PYTHON=${PYTHON_CMD}

NO_STAGE=	yes
do-install:
	@${MKDIR} ${DATADIR}
.for f in kippo.cfg kippo.tac fs.pickle
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}
.endfor
.for d in doc honeyfs kippo txtcmds utils
	@${MKDIR} ${DATADIR}/${d}
	@(cd ${WRKSRC}/${d}/ && ${COPYTREE_SHARE} \* ${DATADIR}/${d})
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
