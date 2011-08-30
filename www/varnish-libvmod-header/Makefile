# New ports collection makefile for:	varnish-libvmod-header
# Date created:				2011-08-23
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	libvmod-header
DISTVERSION=	0.3-3
CATEGORIES=	www
MASTER_SITES=	https://github.com/KristianLyng/libvmod-header/tarball/master/
PKGNAMEPREFIX=	varnish-
DISTNAME=	KristianLyng-${PORTNAME}-${VMOD_HEADER_HASH}
DISTFILES=	KristianLyng-${PORTNAME}-0.3-3-g${VMOD_HEADER_HASH}.tar.gz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Varnish Module (vmod) for manipulation of duplicated headers

LICENSE=	BSD

BUILD_DEPENDS=	${LOCALBASE}/include/varnish/varnishapi.h:${PORTSDIR}/www/varnish \
		rst2man:${PORTSDIR}/textproc/py-docutils

FETCH_ARGS=	-Fpr

USE_AUTOTOOLS=	aclocal libtool libtoolize autoheader automake autoconf
USE_GMAKE=	yes
ACLOCAL_ARGS=	-I m4
LIBTOOLFLAGS=	--copy --force
AUTOMAKE_ARGS=	--add-missing --copy --foreign
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
CFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/varnish

VMOD_HEADER_HASH=	232741d

MAN3=		vmod_header.3

.include <bsd.port.pre.mk>

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
