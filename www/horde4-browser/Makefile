# Ports collection makefile for:  horde4-browser
# Date created:			  THU May 26, 2011
# Whom:				  Beech Rintoul <beech@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	browser
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	Horde_Browser-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Horde browser API

USE_HORDE=	base
USE_GETTEXT=	yes
BRODIR=		Browser
HORDIR+=	${HORBAS}${BRODIR:S|^|/|:S|/horde||}

post-extract:
	@${MKDIR} ${WRKSRC}/config && touch ${WRKSRC}/config/placeholder.dist

do-install:
	@${INSTALL} -d ${HORDIR}/
	@${CP} ${WRKSRC}/lib/Horde/Browser.php ${HORBAS}/
	@${CP} -Rp ${WRKSRC}/lib/Horde/Browser/ ${HORDIR}/
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
