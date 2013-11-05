# Created by: Norberto Lopes <nlopes.ml@gmail.com>
# $FreeBSD$

PORTNAME=	anonymous-pro
PORTVERSION=	1.002
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.marksimonson.com/assets/content/fonts/
DISTNAME=	AnonymousPro-${PORTVERSION}

MAINTAINER=	nlopes.ml@gmail.com
COMMENT=	A fixed width sans designed especially for coders

LICENSE=	OFL11
LICENSE_PERMS=	auto-accept

RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
FONTSDIR=	${PREFIX}/lib/X11/fonts/${PORTNAME}
SUB_LIST=	FONTSDIR=${FONTSDIR}
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${DISTNAME}.001

NO_STAGE=	yes
do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
.endif
	@${MKDIR} ${FONTSDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}

post-install:
	@${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
