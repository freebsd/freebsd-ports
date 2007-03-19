# New ports collection makefile for:	helixplugin
# Date created:	October 22, 2006
# Whom:		Mikhail T <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	hxplugin
PORTVERSION=	20070318
CATEGORIES=	www multimedia
MASTER_SITES=	http://virtual-estates.net/~mi/port-stuff/

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Browser plugin for Real or Helix Players

USE_BZIP2	 =	yes
USE_DOS2UNIX	 =	yes
MAKEFILE	 =	${FILESDIR}/BSDmakefile
#USE_GECKO	 =	firefox mozilla seamonkey xulrunner firefox-devel
USE_GECKO	 =	${_GECKO_ALL}
MAKE_ENV	+=	TOP="${WRKSRC}" GECKO=${GECKO}

PDIR		 ?=	lib/browser_plugins
PLIST_FILES=	${PDIR}/helix.so ${PDIR}/nphelix.xpt

do-install:
	${INSTALL_DATA} ${PLIST_FILES:S|${PDIR}|${WRKSRC}|} ${PREFIX}/${PDIR}/

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/mozilla/bsd.gecko.mk"
.include <bsd.port.post.mk>
