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

do-configure:
	@${SED} -e "s|/usr/X11R6/|${X11BASE}/|" \
		${WRKSRC}/Makefile.FREEBSD > \
		${WRKSRC}/Makefile

post-install:
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 555 \
		${PREFIX}/share/doc/${PORTNAME}
.for file in CHANGES COPYING README TODO
	@${INSTALL_DATA} ${WRKSRC}/../${file} ${PREFIX}/share/doc/${PORTNAME}
.endfor
.endif # !NOPORTDOCS

.include <bsd.port.mk>
