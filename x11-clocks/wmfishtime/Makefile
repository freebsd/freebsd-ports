# New ports collection makefile for:	wmfishtime
# Date created:				31 March 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	wmfishtime
PORTVERSION=	1.2
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/ \
		http://www.freenix.no/~anders/

MAINTAINER=	anders@fix.no

USE_GTK=	yes
USE_X_PREFIX=	yes

pre-build:
	${PERL} -pi -e "s@gcc@${CC}@g; s@-O3@${CFLAGS}@g; \
			s@gtk-config@${GTK_CONFIG}@g; s@-lgtk@-lgtk12@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfishtime ${PREFIX}/bin

.include <bsd.port.mk>
