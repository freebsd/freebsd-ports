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
MASTER_SITES=	SF/mod-acct/mod-acct/${PORTVERSION}
PKGNAMEPREFIX=	${APACHE_PKGNAMEPREFIX}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that records traffic statistics into a database

MAKE_JOBS_SAFE=  yes

OPTIONS=	MYSQL	"Enable MySQL support" on \
			PGSQL	"Enable PGSQL support" on

USE_APACHE=	13
MAKE_ARGS+=	APXS="${APXS}"

.include <bsd.port.options.mk>

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
