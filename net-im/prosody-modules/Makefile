# $FreeBSD$

PORTNAME=	prosody-modules
PORTVERSION=	20200302
CATEGORIES=	net-im
MASTER_SITES=	https://hg.prosody.im/${PORTNAME}/archive/
DISTNAME=	7e7ac4af6e0c
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Prosody Community modules repository snapshot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	prosodyctl:net-im/prosody

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message
SUB_LIST=	INSTALLPATH=${INSTALLPATH}
PLIST_SUB=	INSTALLPATH=${INSTALLPATH}
WRKSRC=		${WRKDIR}/Community-Modules-${DISTNAME}
INSTALLPATH=	${PREFIX}/lib/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${INSTALLPATH} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} mod_*/*.lua ${STAGEDIR}${INSTALLPATH}
	cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
