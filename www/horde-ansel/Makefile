# Ports collection makefile for:	ansel
# Date created:			Mon Mar 19, 2007
# Whom:				Beech Rintoul <beech@alaskaparadise.com>
#
# $FreeBSD$
#

PORTNAME=	ansel
PORTVERSION=	0.1.b20070319
CATEGORIES=	www
MASTER_SITES=	CENKES http://freebsd.alaskaparadise.com/source/
PKGNAMEPREFIX=	horde-

MAINTAINER=	beech@alaskaparadise.com
COMMENT=	Image gallery

RUN_DEPENDS+=	${LOCALBASE}/${LHORDEDIR}/rpc.php:${PORTSDIR}/www/horde-base

NO_BUILD=	yes
USE_APACHE=	1.3+	# needed to test APACHE_VERSION
USE_GETTEXT=	yes
REINPLACE_ARGS=	-i ""

PORTDOCS=	CHANGES CREDITS TODO README
CONFFILE=	conf.xml
SUB_DIRS=	config gallery img js lib locale po scripts templates themes

LHORDEDIR?=	www/horde
LANSDIR=	${LHORDEDIR}/ansel
PEARDIR?=	${LOCALBASE}/share/pear

PLIST_SUB=	ANSDIR=${LANSDIR} HORDE_INC=${HORDE_INC:S|^${LOCALBASE}/||}
PKGMESSAGE=	${WRKDIR}/pkg-message
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
SUB_FILES=	pkg-message pkg-install pkg-deinstall
SUB_LIST=	ANSDIR=${ANSDIR} PORTSDIR=${PORTSDIR} CONFDIR=${CONFDIR}

ANSDIR=		${PREFIX}/${LANSDIR}
CONFDIR=	${ANSDIR}/config

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
	@${SED} -e "s:/home/httpd/html/horde/ansel:${ANSDIR}:" \
		${FILESDIR}/httpd.conf.ansel > ${WRKDIR}/httpd-ansel.conf

do-install:
	@${INSTALL} -d ${ANSDIR}/
	@${CP} -Rp ${SUB_DIRS:S|^|${WRKSRC}/|} ${ANSDIR}/
	@${CP} -p ${WRKSRC}/*.php ${ANSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/config/conf.xml ${CONFDIR}/
	@${INSTALL_DATA} ${WRKDIR}/httpd-ansel.conf ${HORDE_INC}/
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${ANSDIR}/
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
