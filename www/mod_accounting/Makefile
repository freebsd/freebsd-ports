# New ports collection makefile for:	mod_accounting
# Date created:				15 November 2002
# Whom:					Clément Laforêt <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_accounting
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	SF/mod-acct/mod-acct/${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that records traffic statistics into a database

MAKE_JOBS_SAFE=  yes

OPTIONS=	MYSQL	"Enable MySQL support" on \
			PGSQL	"Enable PGSQL support" off

USE_APACHE=	13
MAKE_ARGS+=	APXS="${APXS}"

.include <bsd.port.options.mk>

.if defined(WIT_PGSQL)
USE_PGSQL=	YES
AP_EXTRAS+=	-DNEED_PGSQL
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	YES
AP_EXTRAS+=	-DNEED_MYSQL
.endif

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
PLIST_FILES+=	%%DATADIR%%/schema.sql
PLIST_DIRS+=	%%DATADIR%%

PORTDOCS=		README FAQ.txt LICENSE

post-install:
	@${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/schema.sql ${DATADIR}/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
