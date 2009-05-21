# New ports collection makefile for:	mod_gzip2 Apache module
# Date created:		2008-06-27
# Whom:			Stefan `Sec` Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	mod_gzip2
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.gknw.net/development/apache/httpd-2.0/unix/modules/
DISTNAME=	mod_gzip-${PORTVERSION}

MAINTAINER=	sec@42.org
COMMENT=	An Internet Content Acceleration module for Apache2+

MAKE_JOBS_SAFE=  yes

USE_APACHE=	2.0+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
MAKE_ENV+=	"APXS=${APXS}"
USE_GMAKE=	yes

.if !defined(NOPORTDOCS)
PLIST_FILES=	${DOCSDIR:S/${PREFIX}\///}/commands.txt
PLIST_FILES+=	${DOCSDIR:S/${PREFIX}\///}/samples.txt
PLIST_DIRS=	${DOCSDIR:S/${PREFIX}\///}
.endif
PLIST_FILES+=	share/examples/mod_gzip2/mod_gzip2.conf.sample
PLIST_DIRS+=	share/examples/mod_gzip2

post-patch:
	@${MV} ${WRKSRC}/mod_gzip.c ${WRKSRC}/${PORTNAME}.c

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/my_cfg.txt ${EXAMPLESDIR}/mod_gzip2.conf.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/commands.txt ${WRKSRC}/samples.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
