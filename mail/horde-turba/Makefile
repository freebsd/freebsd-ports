# Ports collection makefile for:  turba
# Date created:			  Sat Nov 16, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	turba
PORTVERSION=	1.2.2
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

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	The Horde contact management application

#-----------------------------------------------------------------------
# You may define this option:
#
# - WITHOUT_LDAP        : if you do not need OpenLDAP;
#
#-----------------------------------------------------------------------

RUN_DEPENDS=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=	yes
.endif

NO_BUILD=	yes
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.beforeTurba
DOCS=		COPYING README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/INSTALL docs/LDAP docs/RELEASE_NOTES docs/UPDATE	\
		docs/turba.dia docs/turba.pdf
CONFFILE=	attributes.php conf.php html.php menu.php prefs.php	\
		sources.php
SUB_DIRS=	config graphics lib locale scripts templates po

LHORDEDIR?=	www/horde
LTURBADIR?=	${LHORDEDIR}/turba

PLIST_SUB=	HORDEDIR=${LHORDEDIR} TURBADIR=${LTURBADIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
TURBADIR=	${PREFIX}/${LTURBADIR}
CONFDIR=	${TURBADIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

post-patch:
	@${RM} ${WRKSRC}/config/conf.php.dist.orig	\
		${WRKSRC}/config/prefs.php.dist.orig	\
		${WRKSRC}/config/sources.php.dist.orig

pre-install:
.if !defined(WITHOUT_LDAP)
	@if ! php -m | ${GREP} -q -e "ldap"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
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
	@${CHOWN} -R www:www ${TURBADIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.turba ${HORDE_INC}
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/turba:${TURBADIR}:g"	\
		${HORDE_INC}/httpd.conf.turba
	@${RM} ${HORDE_INC}/httpd.conf.turba.beforeTurba
	@${REINPLACE_CMD} -e "s://UNCOMMENTWHENINSTTURBA::"			\
		${HORDEDIR}/config/registry.php
	@${CP} -p ${HORDEDIR}/config/registry.php				\
		${HORDEDIR}/config/registry.php.afterTurba
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${SED} -e "s:%%TURBADIR%%:${TURBADIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g"	\
		-e "s:%%CONFDIR%%:${CONFDIR}:g" ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
