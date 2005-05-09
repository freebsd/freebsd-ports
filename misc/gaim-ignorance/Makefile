# New ports collection makefile for:	gaim-ignorance
# Date created:		17 April 2005
# Whom:			kevinb
#
# $FreeBSD$
#

PORTNAME=	ignorance
PORTVERSION=	1.3.0.1
CATEGORIES=	misc
MASTER_SITES=	http://bard.sytes.net/ignorance/
PKGNAMEPREFIX=	gaim-

MAINTAINER=	kruptos@mlinux.org
COMMENT=	Adds filtering capabilities to gaim

BUILD_DEPENDS=	gaim:${PORTSDIR}/net/gaim
RUN_DEPENDS=	gaim:${PORTSDIR}/net/gaim

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

EXAMPLESDIR_REL=${EXAMPLESDIR:S,^${PREFIX}/,,}
PLIST_FILES=	lib/gaim/ignorance.so ${EXAMPLESDIR_REL}/ignorance
PLIST_DIRS=	${EXAMPLESDIR_REL}

SUB_FILES=	pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-g3||' ${WRKSRC}/configure

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ignorance ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
