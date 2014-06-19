# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_cband
PORTVERSION=	0.9.7.5
PORTREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://fossies.org/linux/www/apache_httpd_modules/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/_/-/}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Per-virtualhost bandwidth limiter module for Apache 2

USE_APACHE=	22
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-apxs=${APXS}
ALL_TARGET=	#
PORTDOCS=	libpatricia.copyright documentation.txt faq.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/libpatricia.copyright ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/documentation.txt ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/faq.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
