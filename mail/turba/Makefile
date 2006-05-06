# Ports collection makefile for:  turba
# Date created:			  Sat Nov 16, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	turba
PORTVERSION=	2.1.1
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

MAINTAINER=	shaun@inerd.com
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
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes

REINPLACE_ARGS=	-i ""
DOCS=		README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/LDAP docs/RELEASE_NOTES docs/TODO docs/UPGRADING
CONFFILE=	attributes.php menu.php mime_drivers.php prefs.php sources.php
SUB_DIRS=	config lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LTURBADIR?=	${LHORDEDIR}/turba

PLIST_SUB=	TURBADIR=${LTURBADIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	TURBADIR=${TURBADIR} CONFDIR=${CONFDIR}

TURBADIR=	${PREFIX}/${LTURBADIR}
CONFDIR=	${TURBADIR}/config

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/sbin/imspd)
WITH_IMSP=	yes
.endif
.if defined(WITH_IMSP)
RUN_DEPENDS+=	imspd:${PORTSDIR}/databases/cyrus-imspd
.endif

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

pre-configure:
	@${RM} ${WRKSRC}/config/sources.php.dist.orig
	@${SED} -e "s:/home/httpd/html/horde/turba:${TURBADIR}:g"	\
		${FILESDIR}/httpd.conf.turba > ${WRKDIR}/httpd-turba.conf
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

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${TURBADIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd-turba.conf ${HORDE_INC}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
