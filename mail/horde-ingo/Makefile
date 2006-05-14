# Ports collection makefile for:  Ingo
# Date created:			  Dec 3, 2004
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	ingo
PORTVERSION=	1.1.1
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.horde.org/pub/ingo/				\
		ftp://ftp.planetmirror.com/pub/horde/ingo/		\
		ftp://ftp.au.horde.org/pub/horde/ingo/			\
		ftp://ftp.be.horde.org/ingo/				\
		ftp://ftp.es.horde.org/pub/ingo/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/ingo/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/ingo/	\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/ingo/	\
		http://ftp.horde.org/pub/ingo/
DISTNAME=	${PORTNAME}-h3-${PORTVERSION}

MAINTAINER=	shaun@inerd.com
COMMENT=	Horde\'s email-filter management application

#-----------------------------------------------------------------------
# You may define this option:
#
# - WITH_SIEVE	: if you run timsieved (with Cyrus).
#
#-----------------------------------------------------------------------

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes
USE_PHP=	imap
USE_GETTEXT=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION

PLIST_SUB=	INGODIR=${LINGODIR}  HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	INGODIR=${INGODIR}

DOCS=		LICENSE README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES docs/TODO
CONFFILE=	backends.php fields.php prefs.php
SUB_DIRS=	config lib locale po scripts templates themes js

LHORDEDIR?=	www/horde
LINGODIR=	${LHORDEDIR}/ingo
PEARDIR?=	${LOCALBASE}/share/pear

INGODIR=	${PREFIX}/${LINGODIR}
CONFDIR=	${INGODIR}/config

.include <bsd.port.pre.mk>

.if defined(WITH_SIEVE) || exists(${LOCALBASE}/cyrus/bin/timsieved)
RUN_DEPENDS+=	${PEARDIR}/Net/Sieve.php:${PORTSDIR}/net/pear-Net_Sieve
.endif

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

pre-configure:
	@${SED} -e "s:/home/httpd/html/horde/ingo:${INGODIR}:g"		\
		${FILESDIR}/httpd.conf.ingo >${WRKDIR}/httpd-ingo.conf

do-install:
	@${MKDIR}  ${INGODIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${INGODIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${INGODIR}

	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${INGODIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd-ingo.conf ${HORDE_INC}
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
