# New ports collection makefile for:	bbsmount
# Date created:				11 October 2003
# Whom:				Eric J. Christeson <echriste@702com.net>
#
# $FreeBSD$
#

PORTNAME=	bbsmount
PORTVERSION=	0.3.0p1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://phoenix.inf.upol.cz/~jezberam/bbsmount/files/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/p/pre/}

MAINTAINER=	echriste@702com.net
COMMENT=	Graphical disk mounter for the Blackbox slit

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}
USE_GMAKE=	yes
USE_XLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
	${WRKSRC}/configure

post-install:
	@${ECHO_MSG} "===> Installing documentation"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL} ${WRKSRC}/data/README.bbsmount ${DOCSDIR}

.for a in README BUGS NEWS AUTHORS ChangeLog
	@${INSTALL} ${WRKSRC}/${a} ${DOCSDIR}
.endfor

	if [ ! -e ${PREFIX}/share/bbtools/bbsmount.bb ]; then \
		${CP} -p ${WRKSRC}/data/bbsmount.bb \
		${PREFIX}/share/bbtools/bbsmount.bb; \
	fi
	@${INSTALL} ${WRKSRC}/data/bbsmount.bb ${PREFIX}/share/bbtools/bbsmount.bb-sample

.include <bsd.port.mk>
