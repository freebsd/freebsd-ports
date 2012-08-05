# New ports collection makefile for:	gmime2
# Date created:				16 Apr 2001
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	2.4.32
PORTREVISION?=	0
CATEGORIES?=	mail
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	-24

MAINTAINER?=	ahicks@p-o.co.uk
COMMENT?=	Library (written in C) for parsing and creating messages using MIME

LICENSE=	LGPL21

CONFLICTS=	gmime-1.0.*

SLAVEDIRS=	mail/gmime2-sharp

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}24
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME?=	gnomehack glib20
USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
USE_XZ=		yes
GNU_CONFIGURE=	yes
# www.freebsd.org/cgi/query-pr.cgi?pr=118092
# Rename uudecode and uuencode to gmime-* to not conflict with userland
# fix kept in case issue returns
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--enable-mono=no \
		--program-transform-name="s/uuencode/gmime-uuencode/;s/uudecode/gmime-uudecode/;"
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

LATEST_LINK?=	${PORTNAME}24

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in docs/reference/html/*
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
