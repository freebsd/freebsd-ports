# $FreeBSD$

PORTNAME=	maraschino
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	GH

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	A simple web interface to act as a nice overview/front page for an XBMC HTPC.

LICENSE=	MIT PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	2.5+

USE_GITHUB=	yes
GH_ACCOUNT=	mrkipling
GH_PROJECT=	maraschino
GH_COMMIT=	726bbf0
GH_TAGNAME=	${GH_COMMIT}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

USERS=		media
GROUPS=		media

.include <bsd.port.pre.mk>

do-install:
	${INSTALL} -d ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/maraschino
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/maraschino

.include <bsd.port.post.mk>
