# New ports collection makefile for:   dnrd
# Date created:        06 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       	dnrd
PORTVERSION=		2.10
CATEGORIES=     	net
MASTER_SITES=   	http://members.home.com/garsh/dnrd/archive/

MAINTAINER=		greid@FreeBSD.org

WRKSRC=			${WRKDIR}/${DISTNAME}/src

USE_GMAKE=		yes
USE_REINPLACE=	yes

MAN8=			dnrd.8

post-patch:
.for F in main.c master.c
	@(cd ${WRKSRC} && ${SED} -e 's,%%PREFIX%%,${PREFIX},g' $F > foo && \
		${MV} foo $F)
.endfor
	${REINPLACE_CMD} -e "s@cc@${CC}@g; s@-lc_r@${PTHREAD_LIBS}@g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
