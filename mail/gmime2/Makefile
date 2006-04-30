# New ports collection makefile for:	gmime2
# Date created:				16 Apr 2001
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	gmime
PORTVERSION=	2.2.1
PORTREVISION?=	0
CATEGORIES?=	mail
MASTER_SITES=	http://spruce.sourceforge.net/gmime/sources/v${PORTVERSION:C/([0-9]\.[0-9]).*/\1/}/

MAINTAINER?=	mnag@FreeBSD.org
COMMENT?=	Library (written in C) for parsing and creating messages using MIME

CONFLICTS=	gmime-1.0.*

USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=	--with-libiconv=${LOCALBASE} \
			--with-html-dir=${PREFIX}/share/doc \
			--enable-mono=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

LATEST_LINK?=	${PORTNAME}2

PORTDOCS=	*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in docs/reference/html/*
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
