# Ports collection makefile for:  turba
# Date created:			  Sat Nov 16, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	turba
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/turba/				\
		ftp://ftp.au.horde.org/pub/horde/turba/			\
		ftp://ftp.es.horde.org/pub/turba/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/turba/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/turba/	\
		ftp://ftp.pt.horde.org/pub/horde-ftp/turba/

MAINTAINER=	thierry@pompo.net
COMMENT=	The Horde contact management application

#-----------------------------------------------------------------------
# You may define this option:
#
# - WITHOUT_LDAP        : if you do not need OpenLDAP;
#
#-----------------------------------------------------------------------

.if !defined(WITHOUT_LDAP)
.if exists(${LOCALBASE}/lib/libldap.so.1)
LIB_DEPENDS+=	ldap.1:${PORTSDIR}/net/openldap12
.else
LIB_DEPENDS+=	ldap.2:${PORTSDIR}/net/openldap21-client
.endif
.endif

RUN_DEPENDS+=  ${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2

NO_BUILD=	yes
USE_REINPLACE=	yes

LDD=		/usr/bin/ldd

REINPLACE_ARGS=	-i.beforeTurba
DOCS=		COPYING README docs/CHANGES docs/CREDITS \
		docs/INSTALL docs/LDAP docs/UPDATE docs/turba.dia docs/turba.pdf
CONFFILE=	attributes.php conf.php html.php menu.php \
		prefs.php sources.php
SUB_DIRS=	config graphics lib locale scripts templates po

LHORDEDIR?=	www/horde
LTURBADIR?=	${LHORDEDIR}/turba

PLIST_SUB=	HORDEDIR=${LHORDEDIR} TURBADIR=${LTURBADIR}

HORDEDIR=	${PREFIX}/${LHORDEDIR}
TURBADIR=	${PREFIX}/${LTURBADIR}
CONFDIR=	${TURBADIR}/config

HORDE_INC=	${LOCALBASE}/etc/horde
.if defined(WITH_APACHE2)
PHPSO=		${LOCALBASE}/libexec/apache2/libphp4.so
.else
PHPSO=		${LOCALBASE}/libexec/apache/libphp4.so
.endif

pre-install:
.if !defined(WITHOUT_LDAP)
.if exists(${LOCALBASE}/lib/libldap.so.1)
	@if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libldap.so.1"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.else
	@if ! ${LDD} ${PHPSO} | ${GREP} -q -e "libldap.so.2"; then \
	    ${ECHO_MSG} "" ; \
	    ${ECHO_MSG} "Please configure PHP with OpenLDAP2 support." ; \
	    ${ECHO_MSG} "" ; \
	    ${FALSE} ; \
	fi
.endif
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
	@${CP} -p ${HORDEDIR}/config/registry.php			\
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
	@${CAT} ${PKGMESSAGE} | \
	${SED} -e "s:%%TURBADIR%%:${TURBADIR}:g;s:%%PORTSDIR%%:${PORTSDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g"
	@${ECHO_MSG}

.include <bsd.port.mk>
