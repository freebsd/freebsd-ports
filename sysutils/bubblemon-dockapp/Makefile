# New ports collection makefile for:	bubblemon-dockapp
# Date created:			Apr 16, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	bubblemon-dockapp
PORTVERSION=	1.32
CATEGORIES=	sysutils
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/

MAINTAINER=	mark@kyne.com.au

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
MAKE_ARGS+=	PREFIX="${PREFIX}"

pre-configure:
	${PERL} -pi -e "s@CC = gcc@CC = ${CC}@g; s@-O3 -ansi -Wall@${CFLAGS} -Wall@g; \
			s@PREFIX = /usr/local@PREFIX = ${PREFIX}@g; \
			s@gtk-config@${GTK_CONFIG}@g; s@-lgtk@-lgtk12@g; \
			s@-c -g kmem -m 2755 -o root@-s -c -g kmem -m 2755 -o root@g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
