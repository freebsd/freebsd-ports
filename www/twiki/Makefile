# Ports collection makefile for:  TWiki
# Date created:			  Fri Mar  7 14:36:05 CST 2003
# Whom:				  Justin Hawkins <justin@hawkins.id.au>
#
# $FreeBSD$
#

PORTNAME=	twiki
PORTVERSION=	20040904
CATEGORIES=	www
MASTER_SITES=	http://twiki.org/swd/ \
		http://www.thoeny.com/peter/twiki/
DISTNAME=	TWiki${PORTVERSION}

MAINTAINER=	justin@hawkins.id.au
COMMENT=	A flexible, powerful, and easy to use Web-based collaboration platform

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

WWW_ROOT?=	${WWWOWN}
TWIKIDIR=	${PREFIX}/${WWW_ROOT}/twiki

PLIST_SUB=	WWW_ROOT=${WWW_ROOT}
SUB_LIST=	WWWUSER=${WWWOWN} WWWGROUP=${WWWGRP} TWIKIDIR=${TWIKIDIR} \
		REINPLACE_CMD="${REINPLACE_CMD}"
SUB_FILES=	pkg-install
PKGINSTALL=	${WRKDIR}/pkg-install

pre-everything::
	@${ECHO} "****************************************************************"
	@${ECHO} "*  If you're upgrading, Ctrl-C now and do the upgrade by hand. *"
	@${ECHO} "*  This software can't be upgraded automatically without       *"
	@${ECHO} "*  damaging data in your wiki!                                 *"
	@${ECHO} "****************************************************************"
	@sleep 10

post-extract:
	@# move config to sample
	@${MV} ${WRKSRC}/lib/TWiki.cfg ${WRKSRC}/lib/TWiki.cfg.sample

do-install:
	${INSTALL} -d -m 0755 ${TWIKIDIR}
	(cd ${WRKSRC} && ${FIND} . | \
		${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${TWIKIDIR})

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
