# Ports collection makefile for:  turba
# Date created:			  Sat Nov 16, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	turba
PORTVERSION=	2.0.2
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/turba/				\
		ftp://ftp.planetmirror.com/pub/horde/turba/		\
		ftp://ftp.au.horde.org/pub/horde/turba/			\
		ftp://ftp.be.horde.org/turba/				\
		ftp://ftp.es.horde.org/pub/turba/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/turba/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/turba/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/turba/	\
		http://ftp.horde.org/pub/turba/
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	The Horde contact management application

#-----------------------------------------------------------------------
# You may define this option:
#
# - WITHOUT_LDAP        : if you do not need OpenLDAP;
#
# - WITH_IMSP		: run IMSP cyrus-imspd.
#
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

.if !defined(WITHOUT_LDAP)
USE_PHP=	ldap
.endif

NO_BUILD=	yes
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i ""
DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/LDAP docs/RELEASE_NOTES docs/TODO docs/UPGRADING
CONFFILE=	attributes.php menu.php prefs.php sources.php
SUB_DIRS=	config lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LTURBADIR?=	${LHORDEDIR}/turba

PLIST_SUB=	TURBADIR=${LTURBADIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

TURBADIR=	${PREFIX}/${LTURBADIR}
CONFDIR=	${TURBADIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

.if exists(${LOCALBASE}/sbin/imspd)
WITH_IMSP=	yes
.endif
.if defined(WITH_IMSP)
RUN_DEPENDS+=	imspd:${PORTSDIR}/databases/cyrus-imspd
.endif

pre-configure:
	@${RM} ${WRKSRC}/config/sources.php.dist.orig
	@${SED} -e "s:/home/httpd/html/horde/turba:${TURBADIR}:g"	\
		${FILESDIR}/httpd.conf.turba > ${WRKDIR}/httpd.conf.turba
	@${REINPLACE_CMD} -e "s:/usr/bin/ldapadd:${LOCALBASE}/bin/ldapadd:"	\
		${WRKSRC}/scripts/ldap/addou.pl
.if defined(WITH_IMSP)
	@${REINPLACE_CMD} -e "s://UNCOMMENTIFIMSP ::" ${WRKSRC}/config/sources.php.dist
.endif

do-install:
	@${MKDIR}  ${TURBADIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${TURBADIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${TURBADIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${TURBADIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd.conf.turba ${HORDE_INC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SED} -e "s:%%TURBADIR%%:${TURBADIR}:;s:%%CONFDIR%%:${CONFDIR}:"	\
		< ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
