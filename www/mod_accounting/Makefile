# New ports collection makefile for:	mod_accounting
# Date created:				15 November 2002
# Whom:					Clément Laforêt <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	mod_accounting
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mod-acct

MAINTAINER=	sheepkiller@cultdeadsheep.org
COMMENT=	An Apache module that records traffic statistics into a database

BUILD_DEPENDS+=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13

MAKE_ARGS+=	APXS="${APXS}"
APXS?=		${LOCALBASE}/sbin/apxs

.if defined(WITHOUT_PGSQL)
MAKE_ARGS+=	WITHOUT_PGSQL=YES
.else
LIB_DEPENDS+=	pq.3:${PORTSDIR}/databases/postgresql7
.endif

.if defined(WITHOUT_MYSQL)
MAKE_ARGS+=	WITHOUT_MYSQL=YES
.else
LIB_DEPENDS+=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.endif

pre-everything:
	@${ECHO} "*-----------------------------------------*"
	@${ECHO} "To disable MySQL support just define :"
	@${ECHO} "	WITHOUT_MYSQL=YES"
	@${ECHO} "To disable PostgreSQL support just define :"
	@${ECHO} "	WITHOUT_PGSQL=YES"
	@${ECHO} "*-----------------------------------------*"

post-install:
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/schema.sql ${PREFIX}/share/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/FAQ.txt
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/LICENSE
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
