# Ports collection makefile for:  TWiki
# Date created:			  Fri Mar  7 14:36:05 CST 2003
# Whom:				  Justin Hawkins <justin@hawkins.id.au>
#
# $FreeBSD$
#

PORTNAME=	twiki
PORTVERSION=	4.0.5
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://twiki.org/p/pub/Codev/Release/ \
		${MASTER_SITE_GENTOO}/distfiles/
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	TWiki-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	A flexible, powerful, and easy to use Web-based collaboration platform

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

TWIKI?=		${WWWOWN}/twiki
TWIKIDIR?=	${PREFIX}/${TWIKI}

PLIST_SUB=	TWIKI=${TWIKI}
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

post-patch:
	@${REINPLACE_CMD} -i "" -e "s|\/home\/httpd\/twiki|${TWIKIDIR}|g" \
	${WRKSRC}/twiki_httpd_conf.txt
	@${REINPLACE_CMD} -i "" -e "s|\/home\/httpd\/twiki|${TWIKIDIR}|g" \
	${WRKSRC}/lib/LocalSite.cfg.txt
	@${REINPLACE_CMD} -i "" -e "s|\/home\/httpd\/twiki|${TWIKIDIR}|g" \
	${WRKSRC}/lib/TWiki.cfg
	@${CP} ${WRKSRC}/lib/TWiki.cfg ${WRKSRC}/lib/TWiki.cfg.sample

do-install:
	${INSTALL} -d -m 0755 ${TWIKIDIR}
	(cd ${WRKSRC} && ${FIND} . -not -name .PLIST.mktmp -not -name '.*_done.*' -not -name pkg-install | \
		${CPIO} -pdmu -R${SHAREOWN}:${SHAREGRP} ${TWIKIDIR})

post-install:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
