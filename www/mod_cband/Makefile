# New ports collection makefile for:	mod_cband
# Date created:				Sep 7 2005
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_cband
PORTVERSION=	0.9.7.5
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.sfr-fresh.com/unix/privat/
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/_/-/}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A per-virtualhost bandwidth limiter module for Apache 2

MAKE_JOBS_SAFE=  yes

USE_APACHE=	20+
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-apxs=${APXS}
ALL_TARGET=	#
PORTDOCS=	libpatricia.copyright documentation.txt faq.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/libpatricia.copyright ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/documentation.txt ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/faq.txt ${DOCSDIR}
.else
	@${DO_NADA}
.endif
.include <bsd.port.mk>
