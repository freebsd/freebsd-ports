# New ports collection makefile for:	mod_fcgid for Apache2
# Date created:		13 August 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_fcgid
PORTVERSION=	2.2
CATEGORIES=	www
MASTER_SITES=	SF/mod-fcgid/OldFiles
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	hemi@puresimplicity.net
COMMENT=	An alternative FastCGI module for Apache2

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0+

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 22
MAKE_ARGS+=	top_dir="${LOCALBASE}/share/apache${APACHE_VERSION}"
MAKE_ARGS+=	INCLUDES="-I${LOCALBASE}/include/apache${APACHE_VERSION} -I${LOCALBASE}/include/apr-1"
INSTALL_TARGET=	install-modules-yes
PLIST_SUB+=	APACHE_VERSION=${APACHE_VERSION}
SUB_LIST+=	APACHE_VERSION=${APACHE_VERSION}
.else
MAKE_ARGS+=	top_dir="${LOCALBASE}/share/apache${APACHE_VERSION:S/20/2/}"
MAKE_ARGS+=	INCLUDES="-I${LOCALBASE}/include/apache${APACHE_VERSION:S/20/2/}"
INSTALL_TARGET=	install-modules
PLIST_SUB+=	APACHE_VERSION=${APACHE_VERSION:S/20/2/}
SUB_LIST+=	APACHE_VERSION=${APACHE_VERSION:S/20/2/}
.endif

post-install:
	${MKDIR} -m 700 /var/run/fcgidsock
	${CHOWN} www:www /var/run/fcgidsock
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
