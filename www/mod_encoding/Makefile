# New ports collection makefile for:	mod_encoding
# Date created:		Thursday 13 November 2003
# Whom:			edwin@mavetju.org
#
# $FreeBSD$
#

PORTNAME=	mod_encoding
PORTVERSION=	20021209
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://webdav.todo.gr.jp/download/

MAINTAINER=	edwin@mavetju.org
COMMENT=	Apache module for non-ascii filename interoperability

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

# This port will work with the following version of Apache and anything newer.
# Mostly because of the dependency of mod_dav.
APACHE_VERSION=	1.3.6

PLIST_FILES=	libexec/apache/mod_encoding.so
USE_APACHE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--sbindir=${PREFIX}/sbin \
		--libexecdir=${PREFIX}/libexec/apache \
		--mandir=${PREFIX}/man \
		--sysconfdir=${PREFIX}/etc/apache \
		--datadir=${PREFIX}/share/apache \
		--includedir=${PREFIX}/include/apache \
		--with-apxs=${APXS}

CONFIGURE_ENV=	CPPFLAGS='-I${LOCALBASE}/include/apache -I${LOCALBASE}/include' \
		LIBS='-L${LOCALBASE}/lib' \
		PATH="${PREFIX}/bin:${PREFIX}/sbin:${PATH}"

.include <bsd.port.mk>
