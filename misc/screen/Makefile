# New ports collection makefile for:	screen
# Date created:         25 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	screen
PORTVERSION=	3.9.13
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	screen

MAINTAINER=	cy@FreeBSD.org

GNU_CONFIGURE=	yes
MAN1=		screen.1

post-install:
	@${CP} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/etc/screenrc.sample
	@if [ ! -f ${PREFIX}/etc/screenrc ]; then \
		cp ${PREFIX}/etc/screenrc.sample ${PREFIX}/etc/screenrc ; \
	fi

.include <bsd.port.mk>
