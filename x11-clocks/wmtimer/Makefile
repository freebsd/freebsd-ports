# New ports collection makefile for:	wmtimer
# Date created:			Thu Apr 26 16:46:38 EDT 2001
# Whom:				Patrick Li <pat@databits.net> et al
#
# $FreeBSD$
#

PORTNAME=	wmtimer
PORTVERSION=	2.3
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://home.dwave.net/~jking/wmtimer/

MAINTAINER=	pat@databits.net

# if you change WRKSRC, check install NOPORTDOCS
WRKSRC=		${WRKDIR}/${DISTNAME}/wmtimer
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GTK=	yes
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

.if !defined(BATCH)
HAS_CONFIGURE=	yes
IS_INTERACTIVE=	yes
.endif # !BATCH

pre-patch:
.if defined(IS_INTERACTIVE)
	@${PERL} -pi -ne "s!/bin/bash!${SH}!" ${WRKSRC}/configure
.endif # IS_INTERACTIVE

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmtimer ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/wmtimer
	@${INSTALL_DATA} ${WRKSRC}/../README ${PREFIX}/share/doc/wmtimer
.endif # !NOPORTDOCS

.include <bsd.port.mk>
