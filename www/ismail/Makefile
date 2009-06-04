# New ports collection makefile for:	ismail
# Date created:			18 June 2004
# Whom:				Kelley Reynolds <kelley@insidesystems.net>
#
# $FreeBSD$
#

PORTNAME=	ismail
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	www mail
MASTER_SITES=	http://sunner.semmy.ru/~az/ISMail/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP-based webmail client

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}

NO_BUILD=	yes
USE_PHP=	imap
WANT_PHP_WEB=	yes

SUB_FILES=	pkg-message

OPTIONS=	DOMXML "Use DOMXML for datastore (only with php4.x)" off \
		MYSQL "Use MySQL for datastore" on \
		POSTGRESQL "Use PostgresQL for datastore" off

.include <bsd.port.options.mk>

.ifdef(WITH_DOMXML)
USE_PHP+=	domxml
IGNORE_WITH_PHP=	5
.endif

.ifdef(WITH_MYSQL)
USE_PHP+=	mysql
PLIST_FILES+=	${EXAMPLESDIR_REL}/mysql4.schema
PLIST_DIRS+=	${EXAMPLESDIR_REL}
.endif

.ifdef(WITH_POSTGRESQL)
USE_PHP+=	pgsql
PLIST_FILES+=	${EXAMPLESDIR_REL}/pgsql.schema
PLIST_DIRS+=	${EXAMPLESDIR_REL}
.endif

.include <bsd.port.pre.mk>

LIB_DEPENDS+=	c-client4.9:${PORTSDIR}/mail/cclient

.pre-extract:
.if !defined(WITH_DOMXML) && !defined(WITH_MYSQL) && !defined(WITH_POSTGRESQL)
	@${ECHO_MSG} "Pleasee choose at least one of DOMXML, MYSQL, POSTGRESQL"
	@${FALSE}
.endif

pre-install:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Inside Systems Mail will be installed to ${WWWDIR}"
	@${ECHO_MSG} "Define WWWDIR to change it."
	@${ECHO_MSG} ""

do-install:
	@${MKDIR} ${WWWDIR}
	${TAR} --exclude '*~' -C ${WRKSRC}/${PORTNAME} -cf - . | ${TAR} -C ${WWWDIR} -xf -
	@${CHOWN} -R www:www ${WWWDIR}
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs.html ${DOCSDIR}
.endif
.ifdef(WITH_MYSQL)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/mysql4.schema ${EXAMPLESDIR}
.endif
.ifdef(WITH_POSTGRESQL)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/pgsql.schema ${EXAMPLESDIR}
.endif

post-install:
	@${CAT} ${PKGMEASSAGE}

.include <bsd.port.post.mk>
