# New ports collection makefile for:	wmfishtime
# Date created:				31 March 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	wmfishtime
PORTVERSION=	1.23
CATEGORIES=	x11-clocks windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/software/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_X_PREFIX=	yes

GTK_LIBS?=	`${GTK_CONFIG} --libs`
GTK_CFLAGS?=	`${GTK_CONFIG} --cflags`
MAKE_ARGS+=	CFLAGS="${CFLAGS} -Wall -I${LOCALBASE}/include ${GTK_CFLAGS}" \
		GTK_LIBS="${GTK_LIBS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmfishtime ${PREFIX}/bin

.include <bsd.port.mk>
