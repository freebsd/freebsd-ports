# New ports collection makefile for:	phpnuke
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	phpnuke
PORTVERSION=	6.9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	PHP-Nuke-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automated website package to distribute and manage content

FORBIDDEN=	"SQL injection vulnerability in Php-Nuke <= 7.1.0"
EXPIRATION_DATE=2004-08-20
DEPRECATED=	SQL injection vulnerability in Php-Nuke <= 7.1.0

.if defined(WITH_PHP3)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.else
USE_PHP=	yes
WANT_PHP_WEB=	yes
.endif

USE_MYSQL=	yes

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PHPNUKEWWW=	${PREFIX}/www/${PORTNAME}
DOCS=		ADDONS-MODULES BLOCKS CHANGES CREDITS INSTALL README SUPPORT TODO

pre-everything::
.if !defined(WITH_PHP3)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITH_PHP3 if you want"
	@${ECHO_MSG} "to use PHP Nuke with PHP3. PHP4 is used by default."
	@${ECHO_MSG} ""
.endif

do-install:
	@-${MKDIR} ${PHPNUKEWWW}/html ${PHPNUKEWWW}/sql
	@${CP} -Rp ${WRKDIR}/html ${WRKDIR}/sql ${PHPNUKEWWW}
.if !defined(NOPORTDOCS)
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKDIR}/${FILE} ${PHPNUKEWWW}
.endfor
.endif

post-install:
	@cd ${PREFIX}; ${FIND} ${PHPNUKEWWW:S/^${PREFIX}\///} -type f -o -type l | \
		${SED} -e 's,^\.,${PHPNUKEWWW:S|${PREFIX}/||},' >>${TMPPLIST}
	@cd ${PREFIX}; ${FIND} ${PHPNUKEWWW:S/^${PREFIX}\///} -type d | ${SORT} -r | ${SED} -e 's/^/@dirrm /g' >>${TMPPLIST}

.include <bsd.port.mk>
