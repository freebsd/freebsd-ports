# Ports collection makefile for:  turba
# Date created:			  Sat Nov 16, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	turba
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/turba/tarballs/

MAINTAINER=	thierry@pompo.net

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

#-----------------------------------------------------------------------
# You may define these options:
#
# - WITHOUT_LDAP        : if you do not need OpenLDAP;
# - WITH_LDAP1          : if you prefer OpenLDAP1.
#
# - WITHOUT_SUPPORTED_DB: if you run a database not in the ports tree;
#
#-----------------------------------------------------------------------

.if !defined(WITHOUT_LDAP)
.if defined(WITH_LDAP1)
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap \
		lber.1:${PORTSDIR}/net/openldap
.else
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap2 \
		lber.2:${PORTSDIR}/net/openldap2
.endif
.endif

RUN_DEPENDS+=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde-devel

NO_BUILD=	yes
DOCS=		COPYING README docs/CHANGES docs/CREDITS \
		docs/INSTALL docs/turba.dia docs/turba.pdf
CONFFILE=	attributes.php conf.php html.php menu.php \
		prefs.php sources.php

LHORDEDIR?=	www/horde
LTURBADIR?=	${LHORDEDIR}/turba

PLIST_SUB=	HORDEDIR=${LHORDEDIR} TURBADIR=${LTURBADIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
TURBADIR=	${PREFIX}/${LTURBADIR}
CONFDIR=	${TURBADIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde

pre-install:
# N.B.: database dependencies are binded with mod_php#, neither by Horde nor Turba.
.if !defined(WITHOUT_SUPPORTED_DB)
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "mysqlclient.10" ; then \
	 if ! ${LDCONFIG} -r | ${GREP} -q -e "pq.2" ; then \
	  if ! ${LDCONFIG} -r | ${GREP} -q -e "sybdb.1" ; then \
	   if ! ${LDCONFIG} -r | ${GREP} -q -e "ct.0" ; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with a database support." ; \
	    ${ECHO_MSG} "MySQL, PostgreSQL and Sybase (CTLIB or DBLIB)" ; \
	    ${ECHO_MSG} "can be used with PHP AND Turba." ; \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "(If everything will run on this machine, do not" ; \
	    ${ECHO_MSG} " forget to install the database server-side!)" ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	   fi ; \
	  fi ; \
	 fi ; \
	fi
.endif
.if !defined(WITHOUT_LDAP)
.if defined(WITH_LDAP1)
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "ldap.1"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.else
	@if ! ${LDCONFIG} -r | ${GREP} -q -e "ldap.2"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP2 support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
.endif

do-install:
	@${MKDIR}  ${TURBADIR}
	@${CP} -Rp ${WRKSRC}/config ${WRKSRC}/graphics ${WRKSRC}/lib ${TURBADIR}
	@${CP} -Rp ${WRKSRC}/locale ${WRKSRC}/scripts ${TURBADIR}
	@${CP} -Rp ${WRKSRC}/templates ${WRKSRC}/po ${TURBADIR}
	@${CP} -p  ${WRKSRC}/*.php ${TURBADIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CHOWN} -R www:www ${TURBADIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.turba ${HORDE_INC}
	@${PERL} -pi -e "s:/home/httpd/html/horde/turba:${TURBADIR}:g" \
		${HORDE_INC}/httpd.conf.turba
	@${PERL} -pi -e "s://UNCOMMENTWHENINSTTURBA::" \
		${HORDEDIR}/config/registry.php
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%TURBADIR%%:${TURBADIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g"
	@${ECHO_MSG}

.include <bsd.port.mk>
