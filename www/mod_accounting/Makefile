# New ports collection makefile for:	mod_accounting
# Date created:				15 November 2002
# Whom:					Clément Laforêt <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_accounting
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-acct

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that records traffic statistics into a database

MAKE_JOBS_SAFE=  yes

USE_APACHE=	13
MAKE_ARGS+=	APXS="${APXS}"

.if defined(WITHOUT_PGSQL)
MAKE_ARGS+=	WITHOUT_PGSQL=YES
.else
USE_PGSQL=	YES
.endif

.if defined(WITHOUT_MYSQL)
MAKE_ARGS+=	WITHOUT_MYSQL=YES
.else
USE_MYSQL=	YES
.endif

DOCS=		README FAQ.txt LICENSE

pre-everything::
	@${ECHO} ""
	@${ECHO} "      WITHOUT_MYSQL        Disable MySQL support"
	@${ECHO} "      WITHOUT_PGSQL        Disable PostgreSQL support"
	@${ECHO} ""

post-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/schema.sql ${PREFIX}/share/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
