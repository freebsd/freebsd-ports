# New ports collection makefile for:	helixplugin
# Date created:	October 22, 2006
# Whom:		Mikhail T <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	hxplugin
PORTVERSION=	20080318
CATEGORIES=	www multimedia
MASTER_SITES=	http://virtual-estates.net/~mi/port-stuff/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Browser plugin for Real or Helix Players

USE_BZIP2	 =	yes
USE_DOS2UNIX	 =	yes
MAKEFILE	 =	${FILESDIR}/BSDmakefile
USE_GECKO	 =	libxul
MAKE_ENV	+=	TOP="${WRKSRC}" GECKO=${GECKO}
MAKE_JOBS_SAFE	 =	yes

USE_WEBPLUGINS=	native
WEBPLUGINS_FILES=helix.so nphelix.xpt

PDIR=		${WEBPLUGINS_DIR:S,${PREFIX}/,,}
PLIST_FILES=	${PDIR}/helix.so ${PDIR}/nphelix.xpt
PLIST_DIRS=	${PDIR}

do-install:
	${MKDIR} ${WEBPLUGINS_DIR}
	${INSTALL_DATA} ${WEBPLUGINS_FILES:S|^|${WRKSRC}/|} ${WEBPLUGINS_DIR}/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/firefox/Makefile.webplugins"
.include <bsd.port.post.mk>
