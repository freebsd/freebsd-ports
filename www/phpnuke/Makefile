# New ports collection makefile for:	phpnuke
# Date created:				10 April 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	phpnuke
PORTVERSION=	5.0
CATEGORIES=	www
MASTER_SITES=	ftp://carroll.cac.psu.edu/pub/linux/distributions/mandrake-devel/projects/phpnuke/ \
		ftp://ftp.rpmfind.net/linux/Mandrake-devel/projects/phpnuke/ \
		ftp://gd.tuwien.ac.at/pub/linux/Mandrake-devel/projects/phpnuke/ \
		ftp://mandrake.redbox.cz/Mandrake-devel/projects/phpnuke/ \
		ftp://ftp.proxad.net/pub/Distributions_Linux/Mandrake-devel/projects/phpnuke/
DISTNAME=	PHP-Nuke-${PORTVERSION}

MAINTAINER=	pat@databits.net

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client
.if defined(WITH_PHP4)
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
.else
RUN_DEPENDS+=	${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOCS=		ADDONS-MODULES BUGS CHANGES README TODO

pre-everything:
.if !defined(WITH_PHP4)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Press CTRL-C and define WITH_PHP4 if you want to use PHP Nuke with PHP4.
	@${ECHO_MSG} ""
.endif

do-install:
	${MKDIR} ${PREFIX}/www/phpnuke/html
	${CP} -Rp ${WRKDIR}/html ${WRKDIR}/sql ${PREFIX}/www/phpnuke
.if !defined(NOPORTDOCS)
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKDIR}/${FILE} ${PREFIX}/www/phpnuke
.endfor
.endif

.include <bsd.port.mk>
