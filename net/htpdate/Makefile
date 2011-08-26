# New ports collection makefile for:	htpdate
# Date created:			9 Jun 2005
# Whom:				Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	htpdate
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.clevervest.com/htp/archive/c/ \
		http://twekkel.home.xs4all.nl/htp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Time synchronization over http utility

LICENSE=	GPLv2 # (or later)

USE_BZIP2=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}"

MANCOMPRESSED=	yes
MAN8=		${PORTNAME}.8
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8.gz ${MAN8PREFIX}/man/man8

.include <bsd.port.mk>
