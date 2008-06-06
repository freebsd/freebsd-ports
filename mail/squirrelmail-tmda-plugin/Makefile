# New ports collection makefile for: squirrelmail-tmda-plugin
# Date created:			2006-06-10
# Whom:				Raul Pollicino <email-freebsd@def-defying.com>
#
# $FreeBSD$
#

PORTNAME=	squirrelmail-tmda-plugin
PORTVERSION=	1.0.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.squirrelmail.org/plugins/
DISTNAME=	tmdatools 1.0.2 1.4.2 \(stable\)
DISTFILES=	tmdatools.1.0.2-1.4.2.tar.gz

MAINTAINER=	email-ports@def-defying.com
COMMENT=	Adds TMDA support to SquirrelMail

RUN_DEPENDS=	tmda-filter:${PORTSDIR}/mail/tmda \
		${SQUIRRELDIR}/index.php:${PORTSDIR}/mail/squirrelmail

USE_PERL5=	yes
NO_BUILD=	yes

SQUIRREL_PLUGIN_NAME=	tmdatools
WRKSRC=		${WRKDIR}/tmdatools

.ifndef WITHOUT_WWWDIR
SQUIRRELDIR?=	${PREFIX}/www/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=www/squirrelmail
.else
SQUIRRELDIR?=	${PREFIX}/squirrelmail
PLIST_SUB+=	SQUIRRELDIR=squirrelmail
.endif
TMDATOOLDIR?=	${SQUIRRELDIR}/plugins/${SQUIRREL_PLUGIN_NAME}
PLIST_SUB+=	TMDATOOLDIR=plugins/${SQUIRREL_PLUGIN_NAME}

pre-everything::
	@${ECHO} "The plugin expects SquirrelMail install in ${SQUIRRELDIR}"
	@${ECHO} "To use the old location ${PREFIX}/squirrelmail define WITHOUT_WWWDIR=yes"
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} \
		-e 's|"/usr/local/tmda-1.0.2/"|${TMDATOOLDIR}|g' \
		${WRKSRC}/tmdatools_config.php.sample
	@${RM} ${WRKSRC}/tmdatools_config.php.sample.bak

do-install:
	@${MKDIR} ${TMDATOOLDIR}
	@${CP} -Rp ${WRKSRC}/ ${TMDATOOLDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${TMDATOOLDIR}
	@${RM} -f ${WRKSRC}/tmdatools_config.php.sample.bak

post-install:
	@${ECHO} ""
	@${ECHO} "Refer to ${TMDATOOLDIR}/INSTALL and README for final installation/configuration instructions."
	@${ECHO} ""

.include <bsd.port.mk>
