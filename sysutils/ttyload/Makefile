# ex:ts=8
# New ports collection makefile for:	ttyload
# Date Created:			Nov 21, 2001
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	ttyload
PORTVERSION=	0.4.4
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daveltd.com/src/util/ttyload/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
ALL_TARGET=	default

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; \
		s,^DEBUG,#DEBUG,g ; \
		s,^CFLAGS\t=,CFLAGS+=,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttyload ${PREFIX}/bin

.include	<bsd.port.mk>
