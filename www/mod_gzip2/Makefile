# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 13 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_gzip
PORTVERSION=	1.3.26.1a
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-gzip
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An Internet Content Acceleration module for Apache

USE_APACHE=	yes
MAKE_ENV+=	"APXS=${APXS}"
ALL_TARGET=	build

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/mod_gzip.conf.sample ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/manual/english/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
