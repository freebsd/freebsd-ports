# New ports collection makefile for:    gpp
# Date created:         06 Sep 2001
# Whom:                 Jos Backus <josb@cncdsl.com>
#
# $FreeBSD$
#

PORTNAME=	gpp
PORTVERSION=	2.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.math.polytechnique.fr/cmat/auroux/prog/

MAINTAINER=	jos@catnook.com

USE_REINPLACE=	yes

MAN1=		gpp.1

post-patch:
		${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g; \
			s|gcc -O2 -Wall|${CC} ${CFLAGS}|g" ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/gpp.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
