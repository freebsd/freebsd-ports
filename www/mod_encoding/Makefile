# New ports collection makefile for:	mod_encoding
# Date created:		Thursday 13 November 2003
# Whom:			edwin@mavetju.org
#
# $FreeBSD$
#

PORTNAME=	mod_encoding
PORTVERSION=	20021209
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://webdav.todo.gr.jp/download/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Apache module for non-ASCII filename interoperability

MAKE_JOBS_SAFE=	yes

# This port will work with the following version of Apache and anything newer.
# Mostly because of the dependency of mod_dav.
#APACHE_VERSION=	1.3.6

USE_APACHE=	20+
USE_ICONV=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--bindir=${PREFIX}/bin \
		--sbindir=${PREFIX}/sbin \
		--libexecdir=${APACHEMODDIR} \
		--sysconfdir=${APACHEETCDIR} \
		--includedir=${APACHEINCLUDEDIR} \
		--with-apxs=${APXS}

CONFIGURE_ENV=	LIBS='-L${LOCALBASE}/lib' \
		PATH="${PREFIX}/bin:${PREFIX}/sbin:${PATH}"
CPPFLAGS+=	-I${APACHEINCLUDEDIR} -I${LOCALBASE}/include

PLIST_FILES=	${APACHEMODDIR}/mod_encoding.so

.if ${APACHE_VERSION} == 20
EXTRA_PATCHES=	${PATCHDIR}/apache20_patch
.elif ${APACHE_VERSION} >= 22
EXTRA_PATCHES=	${PATCHDIR}/apache22_patch
.endif

.if !defined(WITHOUT_ICONV_FIX)
EXTRA_PATCHES+=	${PATCHDIR}/iconv_hook-20040430.patch
.endif

.if defined(WITH_QUERYSTRING_FIX)
.if ${APACHE_VERSION} <= 20
EXTRA_PATCHES+=	${PATCHDIR}/queryfix-patch13
.elif ${APACHE_VERSION} >= 22
EXTRA_PATCHES+=	${PATCHDIR}/queryfix-patch22
.endif
.endif

.include <bsd.port.post.mk>
