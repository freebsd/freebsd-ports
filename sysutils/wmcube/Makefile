# New ports collection makefile for:	wmcube
# Date created:				Mon May 28 02:14:47 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmcube
PORTVERSION=	0.98
CATEGORIES=	sysutils windowmaker
MASTER_SITES=	http://boombox.campus.luth.se/files/

MAINTAINER=	pat@databits.net

WRKSRC=		${WRKDIR}/${PORTNAME}/${PORTNAME}
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_XPM=	yes

do-configure:
	@${SED} -e "s|/usr/X11R6/|${X11BASE}/|" \
		${WRKSRC}/Makefile.FREEBSD > \
		${WRKSRC}/Makefile

post-install:
.for file in *.wmc
	@${ECHO} "===>   Installing extra 3d objects in ${PREFIX}/share/${PORTNAME}"
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${PORTNAME}/3dObjects/${file} \
		${PREFIX}/share/${PORTNAME}
.endfor
.ifndef(NOPORTDOCS)
	@${ECHO} "===>   Installing README in ${PREFIX}/share/doc/${PORTNAME}"
	@${ECHO} "===>   Please Read pkg-descr and README for usage information"
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/${PORTNAME}
.for file in CHANGES COPYING README TODO
	@${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif # !NOPORTDOCS
	${SED} -e "s|/usr/X11R6/|${PREFIX}|" ${PKGMESSAGE}

.include <bsd.port.mk>
