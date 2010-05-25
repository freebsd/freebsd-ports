# New ports collection makefile for:	mod_fcgid for Apache2
# Date created:		13 August 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_fcgid
PORTVERSION=	2.3.5
CATEGORIES=	www
MASTER_SITES=		${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	hemi@puresimplicity.net
COMMENT=	An alternative FastCGI module for Apache2

MAKE_JOBS_SAFE=	yes

USE_APACHE=	2.0+

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.apxs

INSTALL_WRKSRC=	${WRKSRC}/modules/fcgid

SUB_FILES=	pkg-message
SUB_LIST+=	APACHEMODDIR=${APACHEMODDIR}
PLIST_SUB+=	APACHEMODDIR=${APACHEMODDIR}

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 22
MAKE_ARGS+=	top_dir="${LOCALBASE}/share/apache${APACHE_VERSION}"
MAKE_ARGS+=	INCLUDES="-I${LOCALBASE}/include/apache${APACHE_VERSION} -I${LOCALBASE}/include/apr-1"
INSTALL_TARGET=	install-modules-yes
DOCSDIR=	${PREFIX}/share/doc/apache22/mod
.else
MAKE_ARGS+=	top_dir="${LOCALBASE}/share/apache${APACHE_VERSION:S/20/2/}"
MAKE_ARGS+=	INCLUDES="-I${LOCALBASE}/include/apache${APACHE_VERSION:S/20/2/}"
INSTALL_TARGET=	install-modules
DOCSDIR=	${PREFIX}/share/doc/apache2/mod
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/manual/mod/mod_fcgid.html ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/docs/manual/mod/mod_fcgid.html.en ${DOCSDIR}
.endif
	${MKDIR} -m 700 /var/run/fcgidsock
	${CHOWN} www:www /var/run/fcgidsock
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
