# Ports collection makefile for:	trean3
# Date created:			Fri Mar 16, 2007
# Whom:				Beech Rintoul <beech@alaskaparadise.com>
#
# $FreeBSD$
#

PORTNAME=	trean
DISTVERSION=	0.1.beta20070316
CATEGORIES=	www
MASTER_SITES=	CENKES
PKGNAMEPREFIX=	horde-

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Bookmark manager

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

USE_BZIP2=	yes
NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes
REINPLACE_ARGS=	-i ""

PORTDOCS=	CHANGES CREDITS INSTALL TODO README
CONFFILE=	conf.xml .htaccess
SUB_DIRS=	config js lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LTREANDIR=	${LHORDEDIR}/trean
PEARDIR?=	${LOCALBASE}/share/pear

PLIST_SUB=	TREANDIR=${LTREANDIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	TREANDIR=${TREANDIR} PORTSDIR=${PORTSDIR} CONFDIR=${CONFDIR}

TREANDIR=	${PREFIX}/${LTREANDIR}
CONFDIR=	${TREANDIR}/config

HOSTNAME?=	`/bin/hostname`
SERVOS?=	${OPSYS}-${OSREL}

PORTREV_H?=	${LOCALBASE}/include/c-client/portrevision.h

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} >= 20
HORDE_INC=	${LOCALBASE}/etc/apache${APACHE_VERSION:S/20/2/}/Includes/
.else
HORDE_INC=	${LOCALBASE}/etc/horde/
.endif

post-extract:
	@${MV} ${WRKSRC}/README ${WRKSRC}/docs/

pre-configure:
	@${REINPLACE_CMD} -e "s:/usr/local:${LOCALBASE}:" ${WRKSRC}/config/conf.xml
	@${SED} -e "s:/home/httpd/html/horde/trean:${TREANDIR}:" \
		${FILESDIR}/httpd.conf.trean > ${WRKDIR}/httpd-trean.conf

do-install:
	@${INSTALL} -d ${TREANDIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${TREANDIR}/
	@${CP} -p ${WRKSRC}/*.php ${TREANDIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${INSTALL_DATA} ${WRKDIR}/httpd-trean.conf ${HORDE_INC}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${TREANDIR}/
	@${CHMOD} -R o-rwx ${CONFDIR}/
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
