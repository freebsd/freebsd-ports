# New ports collection makefile for:	jumpgate
# Date created:				20 March 2001
# Whom:	      				Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	jumpgate
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	leeym@cae.ce.ntu.edu.tw

ALL_TARGET=	generic

pre-build:
	${PERL} -pi.orig -e "s@gcc@${CC}@g; s@-Wall@-Wall ${CFLAGS}@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
