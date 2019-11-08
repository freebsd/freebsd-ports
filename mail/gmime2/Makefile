# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	gmime
PORTVERSION=	2.2.27
PORTREVISION?=	2
CATEGORIES?=	mail
MASTER_SITES=	GNOME
PKGNAMESUFFIX?=	2

MAINTAINER?=	bofh@FreeBSD.org
COMMENT?=	Library (written in C) for parsing and creating messages using MIME

LICENSE=	LGPL21

PORTSCOUT=	limit:^2\.2
CONFLICTS=	gmime-1.0.* gmime-2.4.*

SLAVEDIRS=	mail/gmime2-sharp

USE_GNOME?=	glib20
USES+=		gmake gnome iconv libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
# www.freebsd.org/cgi/query-pr.cgi?pr=118092
# Rename uudecode and uuencode to gmime-* to not conflict with userland
CONFIGURE_ARGS?=	${ICONV_CONFIGURE_BASE} \
			--with-html-dir=${PREFIX}/share/doc \
			--enable-mono=no \
			--program-transform-name="s/uuencode/gmime-uuencode/;s/uudecode/gmime-uudecode/;"
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e "s|stdint.h|inttypes.h|" ${WRKSRC}/zentimer.h
	@${REINPLACE_CMD} -e 's|-DG_DISABLE_DEPRECATED||g' \
		${WRKSRC}/gmime/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in docs/reference/html/*
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
