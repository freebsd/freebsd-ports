# New ports collection makefile for:	mod_log_spread
# Date created:			08 May 2005
# Whom:				Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	mod_log_spread
PORTVERSION=	1.0.4
CATEGORIES=	www net
MASTER_SITES=	http://www.lethargy.org/mod_log_spread/

MAINTAINER=	meno.abels@adviser.com
COMMENT=	An Apache module interfacing with spread

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread
BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_APACHE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGELOG INSTALL LICENSE README README.spread \
		error_log_spread.pl sample_configurations.txt \
		spreadlogd.README spread.html
.endif

do-build:
	cd ${WRKSRC} && ${APXS} -I${PREFIX}/include -c mod_log_spread.c

do-install:
	${APXS} -i -a -n log_spread ${WRKSRC}/mod_log_spread.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
