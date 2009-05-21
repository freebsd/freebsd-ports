# New ports collection makefile for:	mod_gzip Apache module
# Date created:		Dec 13 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	mod_gzip
PORTVERSION=	1.3.26.1a
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ale@FreeBSD.org
COMMENT=	An Internet Content Acceleration module for Apache

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
MAKE_ENV+=	"APXS=${APXS}"
ALL_TARGET=	build

post-patch:
	@${REINPLACE_CMD} 's|-Wc,-Wall,-O3,-fomit-frame-pointer,-pipe||' \
		${WRKSRC}/Makefile

PORTEXAMPLES=	${PORTNAME}.conf.sample

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}/
	@${INSTALL_DATA} ${WRKSRC}/docs/${PORTNAME}.conf.sample ${EXAMPLESDIR}/
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/docs/manual/english/* ${DOCSDIR}/
.endif

.include <bsd.port.mk>
