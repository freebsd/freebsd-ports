# New ports collection makefile for:	gmime2
# Date created:				16 Apr 2001
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	2.2.27
PORTREVISION?=	0
CATEGORIES?=	mail
MASTER_SITES=	GNOME

MAINTAINER?=	ahicks@p-o.co.uk
COMMENT?=	Library (written in C) for parsing and creating messages using MIME

LICENSE=	LGPL21

CONFLICTS=	gmime-1.0.* gmime-2.4.*

SLAVEDIRS=	mail/gmime2-sharp

USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME?=	gnomehack glib20
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
# www.freebsd.org/cgi/query-pr.cgi?pr=118092
# Rename uudecode and uuencode to gmime-* to not conflict with userland
CONFIGURE_ARGS?=	--with-libiconv=${LOCALBASE} \
			--with-html-dir=${PREFIX}/share/doc \
			--enable-mono=no \
			--program-transform-name="s/uuencode/gmime-uuencode/;s/uudecode/gmime-uudecode/;"
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

LATEST_LINK?=	${PORTNAME}2

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e "s|stdint.h|inttypes.h|" ${WRKSRC}/zentimer.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in docs/reference/html/*
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
