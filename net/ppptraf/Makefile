# New ports collection makefile for:	ppptraf
# Date created:		9 February 2000
# Whom:			diskiller@cnbinc.com
#
# $FreeBSD$
#

PORTNAME=	ppptraf
PORTVERSION=	1.0
CATEGORIES=	net
MASTER_SITES=	http://people.FreeBSD.org/~dburr/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A ncurses based PPP Traffic (bytes in/out) monitoring program

DEPRECATED=	"author has abandoned this program"

#MAN1=		ppptraf.1

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local,${PREFIX}," ${WRKSRC}/Makefile

.include <bsd.port.mk>
