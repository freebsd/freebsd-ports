# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	mod_fcgid
PORTVERSION=	2.3.9
CATEGORIES=	www
MASTER_SITES=		APACHE_HTTPD/${PORTNAME}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DIST_SUBDIR=	apache2

MAINTAINER=	freebsd.ports@webstyle.ch
COMMENT=	Alternative FastCGI module for Apache2

LICENSE=	APACHE20

USES=		apache:2.2+ cpe
CPE_VENDOR=	apache

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	configure.apxs

INSTALL_WRKSRC=	${WRKSRC}/modules/fcgid

SUB_FILES=	pkg-message
SUB_LIST+=	APACHEMODDIR=${APACHEMODDIR}
PLIST_SUB+=	APACHEMODDIR=${APACHEMODDIR}

MAKE_ARGS+=	top_dir="${LOCALBASE}/share/apache${APACHE_VERSION}"
MAKE_ARGS+=	INCLUDES="-I${LOCALBASE}/include/apache${APACHE_VERSION} -I${LOCALBASE}/include/apr-1"
INSTALL_TARGET=	install-modules-yes
DOCSDIR=	${PREFIX}/share/doc/apache${APACHE_VERSION}/mod

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/fcgidsock

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/manual/mod/mod_fcgid.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/manual/mod/mod_fcgid.html.en ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
