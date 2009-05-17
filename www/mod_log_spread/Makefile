# New ports collection makefile for:	mod_log_spread
# Date created:			08 May 2005
# Whom:				Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	mod_log_spread
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	www net
MASTER_SITES=	http://www.lethargy.org/${PORTNAME}/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module interfacing with spread

LIB_DEPENDS=	spread.1:${PORTSDIR}/net/spread
BUILD_DEPENDS=	${APXS}:${PORTSDIR}/${APACHE_PORT}
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

AP_INC=	${LOCALBASE}/include
AP_LIB=	${LOCALBASE}/lib -lspread

PORTDOCS=	CHANGELOG INSTALL LICENSE README README.spread \
		error_log_spread.pl sample_configurations.txt \
		spreadlogd.README spread.html

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
.for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
