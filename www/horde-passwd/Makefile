# Ports collection makefile for:  horde-passwd
# Date created:			  Thu Feb 12, 2004
# Whom:				  João Carlos Mendes Luís (<jonny@jonny.eng.br>)
#
# $FreeBSD$
#

PORTNAME=	horde-passwd
PORTVERSION=	2.2.1
CATEGORIES=	www mail
MASTER_SITES=	ftp://ftp.horde.org/pub/passwd/				\
		ftp://ftp.au.horde.org/pub/horde/passwd/		\
		ftp://ftp.es.horde.org/pub/passwd/			\
		ftp://ftp.it.horde.org/pub/mirror/horde.org/passwd/	\
		ftp://ftp.nl.horde.org/mirror/horde-ftp/pub/passwd/	\
		ftp://ftp.pt.horde.org/pub/horde-ftp/passwd/
DISTNAME=	passwd-${PORTVERSION}
DIST_SUBDIR=	horde

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A password changing module for Horde

RUN_DEPENDS+=	${LOCALBASE}/www/horde/index.php:${PORTSDIR}/www/horde2

NO_BUILD=	yes
USE_REINPLACE=	yes

REINPLACE_ARGS=	-i.beforePWD

DOCS=		LICENSE README docs/CHANGES docs/CREDITS docs/INSTALL	\
		docs/RELEASE_NOTES
SUB_DIRS=	config graphics lib locale po scripts templates
CONFFILE=	conf.php backends.php

LHORDEDIR?=	www/horde
LPWDDIR?=	${LHORDEDIR}/passwd

HORDEDIR=	${PREFIX}/${LHORDEDIR}
PWDDIR=		${PREFIX}/${LPWDDIR}
CONFDIR=	${PWDDIR}/config
HCONFDIR=	${HORDEDIR}/config

PLIST_SUB=	LPWDDIR=${LPWDDIR} PWDDIR=${PWDDIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

HORDE_INC=	${PREFIX}/etc/horde

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
	@${REINPLACE_CMD} -e "s:/home/httpd/html/horde/passwd:${PWDDIR}:g"	\
		${HORDE_INC}/httpd.conf.pwd
	@${RM} ${HORDE_INC}/httpd.conf.pwd.beforePWD
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${ECHO_MSG}
	@${SED} -e "s:%%PWDDIR%%:${PWDDIR}:g;s:%%CONFDIR%%:${CONFDIR}:g;"	\
		-e "s:%%HCONFDIR%%:${HCONFDIR}:g" ${FILESDIR}/pkg-message.in	\
		> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
