# Ports collection makefile for:  horde4-auth
# Date created:			  Sun May 22, 2011
# Whom:				  Beech Rintoul (<beech@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	auth
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=
DISTVERSIONSUFFIX=
CATEGORIES=	security www
MASTER_SITES=		http://pear.horde.org/get/ \
			LOCAL/beech
PKGNAMEPREFIX=	horde4-
DISTNAME=	Horde_Auth-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Common interface to backends for Horde authentication

USE_HORDE=	base
USE_GETTEXT=	yes

EXTRACT_SUFX=	.tgz

post-extract:
	@${MKDIR} ${WRKSRC}/config && touch ${WRKSRC}/config/placeholder.dist

do-install:
	@${INSTALL} -d ${HORDIR}/
	@${CP} ${WRKSRC}/lib/Horde/Auth.php ${HORBAS}/
	@${CP} -Rp ${WRKSRC}/lib/Horde/Auth/ ${HORDIR}/
	@${ECHO_CMD} @exec ${CHOWN} -R ${WWWOWN}:${WWWGRP} %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} @exec ${CHMOD} -R o-rwx %D/${HORDIR:S|^${PREFIX}/||}/ >> ${TMPPLIST}
	@${ECHO_CMD} "@exec ${TOUCH} ${HORLOG};${CHOWN} ${WWWOWN}:${WWWGRP} ${HORLOG}" >> ${TMPPLIST}

	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include "${.CURDIR}/../../www/horde4-base/bsd.horde4.mk"
.include <bsd.port.mk>
