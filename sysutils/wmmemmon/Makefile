# New ports collection makefile for:	wmmemmon
# Date created:				Wed May  9 17:55:21 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmmemmon
PORTVERSION=	0.3.1
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://www.sh.rim.or.jp/~ssato/src/
DISTNAME=	WMMemMon-${PORTVERSION}

MAINTAINER=	pat@databits.net

LIB_DEPENDS=	dockapp.1:${PORTSDIR}/x11-wm/libdockapp

ONLY_FOR_ARCHS=	i386
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_AUTOCONF=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/wmmemmon ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
