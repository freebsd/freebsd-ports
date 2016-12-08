# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	gmime
PORTVERSION=	2.6.20
PORTREVISION?=	1
CATEGORIES?=	mail
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	26

MAINTAINER?=	bofh@FreeBSD.org
COMMENT?=	Library (written in C) for parsing and creating messages using MIME

LICENSE=	LGPL21

SLAVEDIRS=	mail/gmime26-sharp

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}26
USES=		gmake iconv libtool pathfix pkgconfig tar:xz
USE_GNOME+=	glib20
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
# www.freebsd.org/cgi/query-pr.cgi?pr=118092
# Rename uudecode and uuencode to gmime-* to not conflict with userland
# fix kept in case issue returns
CONFIGURE_ARGS?=--with-html-dir=${PREFIX}/share/doc \
		--enable-mono=no \
		--program-transform-name="s/uuencode/gmime-uuencode/;s/uudecode/gmime-uudecode/;"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s/tests//' \
		${WRKSRC}/Makefile.in


post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in docs/reference/html/*
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
