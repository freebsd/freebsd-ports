# New ports collection makefile for:	wmScoreBoard
# Date created:				Sun Jun 24 17:08:15 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	wmScoreBoard
PORTVERSION=	0.30
CATEGORIES=	misc windowmaker
MASTER_SITES=	http://home.att.net/~takuper/wmscoreboard/

MAINTAINER=	pat@FreeBSD.org

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 755 \
		${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/../BUGS ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/../CHANGES ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/../HINTS ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
