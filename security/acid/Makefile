# New ports collection makefile for:	acid
# Date created:		Mon Sep 25 16:05:01 CST 2000
# Whom:			Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acid
PORTVERSION=	0.9.4
CATEGORIES=	security
MASTER_SITES=	http://www.cert.org/kb/acid/
DISTFILES=	acid.0.9.4.tar.gz
WRKSRC=		${WRKDIR}/${PORTNAME}

MAINTAINER=	foxfair@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/sbin/httpd:${PORTSDIR}/www/apache13 \
		${LOCALBASE}/libexec/apache/libphp3.so:${PORTSDIR}/www/mod_php3 \
		${LOCALBASE}/libexec/mysqld:${PORTSDIR}/databases/mysql323-server \
		${LOCALBASE}/bin/snort:${PORTSDIR}/security/snort

post-configure:
	${MKDIR} ${LOCALBASE}/share/doc/apache/acid
	${CP} ${FILESDIR}/Makefile.acid ${WRKSRC}/Makefile

post-install:
	@${ECHO} "*****************************************************************************"
	@${ECHO} "Please modify the file '${LOCALBASE}/share/doc/apache/acid/acid_conf.php',   "
	@${ECHO} "and customize the following variables to fit your system:		       "
	@${ECHO} "									       "
	@${ECHO} "'alert_dbname'    : MySQL database name where the alerts are stored 	       "
	@${ECHO} "'alert_host'      : host where the database is stored		       	       "
	@${ECHO} "'alert_port'      : port where the database is stored		               "
	@${ECHO} "'alert_user'      : username into the database			       "
	@${ECHO} "'alert_password'  : password for the username				       "
	@${ECHO} "*****************************************************************************"

.include <bsd.port.mk>
