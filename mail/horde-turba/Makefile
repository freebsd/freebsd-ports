# Ports collection makefile for:  turba
# Date created:			  Sat Nov 16, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	turba
PORTVERSION=	2.1.4
DISTVERSIONPREFIX=	h3-
PORTREVISION=	1
CATEGORIES=	mail www
MASTER_SITES=	HORDE

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	The Horde contact management application

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

USE_PHP=	ldap
NO_BUILD=	yes
USE_GETTEXT=	yes

REINPLACE_ARGS=	-i ""
PORTDOCS=	README CHANGES CREDITS INSTALL LDAP \
		RELEASE_NOTES TODO UPGRADING
CONFFILE=	attributes.php menu.php mime_drivers.php prefs.php sources.php
SUB_DIRS=	config lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LTURBADIR?=	${LHORDEDIR}/turba

PLIST_SUB=	TURBADIR=${LTURBADIR}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	TURBADIR=${TURBADIR} CONFDIR=${CONFDIR}

TURBADIR=	${PREFIX}/${LTURBADIR}
CONFDIR=	${TURBADIR}/config

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

pre-configure:
	@${RM} ${WRKSRC}/config/sources.php.dist.orig
	@${REINPLACE_CMD} -e "s:/usr/bin/ldapadd:${LOCALBASE}/bin/ldapadd:"	\
		${WRKSRC}/scripts/ldap/addou.pl

do-install:
	@${INSTALL} -d ${TURBADIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${TURBADIR}/
	@${CP} -p ${WRKSRC}/*.php ${TURBADIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${TURBADIR}/
	@${CHMOD} -R o-rwx ${TURBADIR}/
	${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP}\
		%D/${TURBADIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	${ECHO_CMD} @exec ${CHMOD} -R o-rwx\
		%D/${TURBADIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/docs/|} ${DOCSDIR}/
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

post-install:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
