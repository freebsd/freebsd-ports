# Ports collection makefile for:   ekg
# Date created:        24 March 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$

PORTNAME=		ekg
PORTVERSION=		1.4
PORTREVISION=	1
PORTEPOCH=		1
CATEGORIES=		polish net
MASTER_SITES=		http://dev.null.pl/ekg/archive/
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		jacek@combit.com.pl
COMMENT=		Text-mode Gadu-Gadu client

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		gnomehack
CONFIGURE_ARGS+=	--enable-shared \
			--disable-static \
			--enable-dynamic \
			--mandir=${PREFIX}/man

INSTALLS_SHLIB=	yes

MAN1=		ekg.1
MANLANG=	"" pl
MANCOMPRESSED=	no

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ekg
	${RM} ${PREFIX}/lib/libgadu.so ${PREFIX}/lib/libgadu.so.3
	${MV} ${PREFIX}/lib/libgadu.so.3.0 ${PREFIX}/lib/libgadu.so.3
	${LN} -s ${PREFIX}/lib/libgadu.so.3 ${PREFIX}/lib/libgadu.so

.include <bsd.port.mk>
