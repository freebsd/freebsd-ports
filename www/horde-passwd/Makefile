# Ports collection makefile for:  horde-passwd
# Date created:			  Thu Feb 12, 2004
# Whom:				  João Carlos Mendes Luís (<jonny@jonny.eng.br>)
#
# $FreeBSD$
#

PORTNAME=	horde-passwd
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	www mail
MASTER_SITES=	ftp://ftp.horde.org/pub/passwd/				\
		ftp://ftp.planetmirror.com/pub/horde/passwd/		\
		ftp://ftp.au.horde.org/pub/horde/passwd/		\
		ftp://ftp.be.horde.org/passwd/				\
		ftp://ftp.es.horde.org/pub/passwd/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/passwd/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/passwd/	\
		http://ftp.horde.org/pub/passwd/			\
		ftp://ftp.uk.horde.org/mirrors/ftp.horde.org/pub/passwd/
DISTNAME=	passwd-h3-${PORTVERSION}
DIST_SUBDIR=	horde

MAINTAINER=	shaun@inerd.com
COMMENT=	A password changing module for Horde

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION

PLIST_SUB=	LPWDDIR=${LPWDDIR} PWDDIR=${PWDDIR}	\
		HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	PWDDIR=${PWDDIR} CONFDIR=${CONFDIR} HORDEDIR=${HORDEDIR}

DOCS=		LICENSE README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES docs/TODO
SUB_DIRS=	config lib locale po scripts templates themes
CONFFILE=	backends.php

LHORDEDIR?=	www/horde
LPWDDIR?=	${LHORDEDIR}/passwd

HORDEDIR=	${PREFIX}/${LHORDEDIR}
PWDDIR=		${PREFIX}/${LPWDDIR}
CONFDIR=	${PWDDIR}/config

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes
.else
HORDE_INC=	${LOCALBASE}/etc/horde
.endif

pre-configure:
	@${SED} -e "s:/home/httpd/html/horde/passwd:${PWDDIR}:g"	\
		${FILESDIR}/httpd.conf.pwd > ${WRKDIR}/httpd-pwd.conf

do-install:
	@${MKDIR}  ${PWDDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${PWDDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${PWDDIR}

	@${CHOWN} -R www:www ${PWDDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${INSTALL_DATA} ${WRKDIR}/httpd-pwd.conf ${HORDE_INC}
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
