# Ports collection makefile for:  pear-Auth
# Date created:			  2 February 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Auth
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	security www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR authentication methods

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../devel/pear-PEAR/Makefile.common"

MANIFEST=	Auth.php Container Container.php

do-install:
	@${MKDIR} ${PEARDIR}/Auth
.for FILE in ${MANIFEST}
	@${CP} -Rp ${WRKSRC}/${FILE} ${PEARDIR}/Auth
.endfor
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PEARDIR}/Auth
	@${CHMOD} -R a-x ${PEARDIR}/Auth/Container/*.php

.include <bsd.port.post.mk>
