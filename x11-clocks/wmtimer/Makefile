# New ports collection makefile for:	wmtimer
# Date created:			Thu Apr 26 16:46:38 EDT 2001
# Whom:				Patrick Li <pat@databits.net> et al
#
# $FreeBSD$
#

PORTNAME=	wmtimer
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://home.dwave.net/~jking/wmtimer/

MAINTAINER=	pat@FreeBSD.org
COMMENT=	Multi-Function timer dockapp for WindowMaker

WRKSRC=		${WRKDIR}/${DISTNAME}/wmtimer
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmtimer ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif # !NOPORTDOCS

.include <bsd.port.mk>
