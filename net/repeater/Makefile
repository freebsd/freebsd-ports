# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	repeater
PORTVERSION=	0.14
CATEGORIES=	net
MASTER_SITES=	http://koti.mbnet.fi/jtko/uvncrepeater/
DISTNAME=	repeater${PORTVERSION:C/\.//}

MAINTAINER=	rick@sloservers.com
COMMENT=	UltraVNC repeater

USES=		zip
USE_RC_SUBR=	repeater
WRKSRC=		${WRKDIR}/Ver${PORTVERSION:C/\.//}
ALL_TARGET=	repeater

REP_USER?=	uvncrep
REP_GROUP?=	uvncrep

SUB_FILES=	pkg-install pkg-message
SUB_LIST=	REP_USER=${REP_USER} REP_GROUP=${REP_GROUP}

PLIST_FILES=	sbin/repeater etc/uvncrepeater.ini.sample
PORTDOCS=	changelog.txt readme.txt ultravncrepeaterlinuxport.html

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/repeater ${PREFIX}/sbin/repeater
	${INSTALL_DATA} ${WRKSRC}/uvncrepeater.ini ${PREFIX}/etc/uvncrepeater.ini.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

post-install:
	@${SETENV} @PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
