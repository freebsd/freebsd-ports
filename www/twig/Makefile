# New ports collection makefile for:	twig
# Date created:				12 Jun 2002
# Whom:					dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	twig
PORTVERSION=	2.7.7
PORTREVISION=	1
CATEGORIES=	www mail
MASTER_SITES=	http://www.informationgateway.org/download/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Web Based Email Client and Scheduler

.if !defined(WITH_PHP3)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/${PHP4_PORT}
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/${PHP3_PORT}
.endif
.if !defined(WITH_MYSQL)
LIB_DEPENDS+=	pq.3:${PORTSDIR}/${POSTGRESQL_PORT}
.else
.endif

NO_BUILD=	YES
PHP4_PORT?=	www/mod_php4-twig
PHP3_PORT?=	www/mod_php3
TWIG?=		www/data-dist/twig
POSTGRESQL_PORT?=	databases/postgresql-client
PLIST_SUB+=	TWIG=${TWIG}
ROOTFILES=	index.php3 test.php3 goto.php3
CONFFILES=	.htaccess mailfooter.inc.php3.sample
USERFILES=	announcements.inc.php3 config.inc.php3 dbconfig.inc.php3 \
		defaults.inc.php3 footer.inc.php3 header.inc.php3 \
		images.inc.php3 login.footer.inc.php3 login.form.php3 \
		login.header.inc.php3 mainmenu.inc.php3 newusergroups.inc.php3

do-install:
	-${MKDIR} ${PREFIX}/${TWIG}/config
	@(cd ${WRKSRC} && ${CP} ${ROOTFILES} ${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R features  ${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R images    ${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC} && ${CP} -R lib       ${PREFIX}/${TWIG}/ )
	@(cd ${WRKSRC}/config && ${CP} ${CONFFILES} ${PREFIX}/${TWIG}/config/ )
.for i in ${USERFILES}
	@${CP} ${WRKSRC}/config/${i} ${PREFIX}/${TWIG}/config/${i}-dist
	@if test ! -f ${PREFIX}/${TWIG}/config/${i} ; then \
		${CP} ${WRKSRC}/config/${i} ${PREFIX}/${TWIG}/config/${i}; \
	fi
.endfor

.include <bsd.port.mk>
