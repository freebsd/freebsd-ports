# $FreeBSD$

PORTNAME=	sickbeard
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	GH

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	PVR & episode guide that downloads and manages all your TV shows

LICENSE=	GPLv3 PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	cheetah:${PORTSDIR}/devel/py-cheetah \
		${PYTHON_SITELIBDIR}/pythonutils/configobj.py:${PORTSDIR}/devel/py-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	2.5+

USE_GITHUB=     yes
GH_ACCOUNT=     midgetspy  
GH_PROJECT=     Sick-Beard
GH_COMMIT=      f6d5fa0
GH_TAGNAME=     ${GH_COMMIT}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

USERS=		media
GROUPS=		media

OPTIONS_DEFINE=	OPENSSL PIL LXML
OPTIONS_DEFAULT=	OPENSSL PIL LXML
PIL_DESC=	image resizing support
LXML_DESC=	xml and html processor used in TPB branch

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl
.endif

.if ${PORT_OPTIONS:MPIL}
RUN_DEPENDS+=   ${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging
.endif

.if ${PORT_OPTIONS:MLXML}
RUN_DEPENDS+=   ${PYTHON_SITELIBDIR}/lxml:${PORTSDIR}/devel/py-lxml
.endif

do-install:
	${INSTALL} -d ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/Sick-Beard
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/Sick-Beard

.include <bsd.port.post.mk>
