# $FreeBSD$

PORTNAME=	htpc-manager
PORTVERSION=	1.0
CATEGORIES=	multimedia
MASTER_SITES=	GH

MAINTAINER=	joshruehlig@gmail.com
COMMENT=	Htpc Manager combines all your favorite software into one slick interface.

LICENSE=	GPLv3 PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	2.7+

USE_GITHUB=     yes
GH_ACCOUNT=     styxit  
GH_PROJECT=     HTPC-Manager
GH_COMMIT=      96c645d
GH_TAGNAME=     ${GH_COMMIT}

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_COMMIT}
PLIST_SUB=	PORTNAME=${PORTNAME}
SUB_LIST+=	PORTNAME=${PORTNAME}
SUB_FILES=	pkg-message
USE_RC_SUBR=	${PORTNAME}

USERS=		media
GROUPS=		media

OPTIONS_DEFINE=	OPENSSL PIL
OPTIONS_DEFAULT=	OPENSSL PIL
PIL_DESC=	convert and resize images retrieved from the XBMC API

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MOPENSSL}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/OpenSSL/SSL.so:${PORTSDIR}/security/py-openssl
.endif

.if ${PORT_OPTIONS:MPIL}
RUN_DEPENDS+=   ${PYTHON_SITELIBDIR}/PIL/_imaging.so:${PORTSDIR}/graphics/py-imaging
.endif

do-install:
	${INSTALL} -d ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/HTPC-Manager
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${STAGEDIR}${DATADIR}/HTPC-Manager

.include <bsd.port.post.mk>
