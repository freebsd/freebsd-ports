# Ports collection makefile for:  horde-passwd
# Date created:			  Thu Feb 12, 2004
# Whom:				  João Carlos Mendes Luís (<jonny@jonny.eng.br>)
#
# $FreeBSD$
#

PORTNAME=	horde-passwd
PORTVERSION=	3.0
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

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A password changing module for Horde

RUN_DEPENDS=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde

NO_BUILD=	yes

PLIST_SUB=	LPWDDIR=${LPWDDIR} PWDDIR=${PWDDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
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

HORDE_INC=	${LOCALBASE}/etc/horde

pre-configure:
	@${SED} -e "s:/home/httpd/html/horde/passwd:${PWDDIR}:g"	\
		${FILESDIR}/httpd.conf.pwd > ${WRKDIR}/httpd.conf.pwd

do-install:
	@${MKDIR}  ${PWDDIR}
.for REP in ${SUB_DIRS}
	@${CP} -Rp ${WRKSRC}/${REP} ${PWDDIR}
.endfor
	@${CP} -p  ${WRKSRC}/*.php ${PWDDIR}
.for FILE in ${CONFFILE}
	@if [ ! -f ${CONFDIR}/${FILE} ]; then \
	  ${CP} ${CONFDIR}/${FILE}.dist ${CONFDIR}/${FILE} ; \
	fi
.endfor
	@${CHOWN} -R www:www ${PWDDIR}
	@${CHMOD} -R o-rwx ${CONFDIR}
	@${CP} -p ${FILESDIR}/httpd.conf.pwd ${HORDE_INC}/httpd.conf.pwd
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
