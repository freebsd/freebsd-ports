# New ports collection makefile for:	screen
# Date created:         25 Nov 1994
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	screen
PORTVERSION=	4.0.2
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.uni-erlangen.de/pub/utilities/screen/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	screen

MAINTAINER=	cy@FreeBSD.org
COMMENT=	A multi-screen window manager

GNU_CONFIGURE=	yes
MAN1=		screen.1
INFO=		screen

NO_PACKAGE=	Tends to loop using 100% CPU when used from package - perhaps it hard-codes information about the build host

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
CFLAGS+=	-O0
.endif

post-patch:
	@${RM} ${WRKSRC}/doc/screen.info*

post-install:
	@${CP} ${WRKSRC}/etc/etcscreenrc ${PREFIX}/etc/screenrc.sample
	@if [ ! -f ${PREFIX}/etc/screenrc ]; then \
		${CP} ${PREFIX}/etc/screenrc.sample ${PREFIX}/etc/screenrc ; \
	fi

.include <bsd.port.post.mk>
