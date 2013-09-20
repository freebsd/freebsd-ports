# Created by: Joe Horn <joehorn@gmail.com>
# $FreeBSD$

PORTNAME=	CKEditor
PORTVERSION=	4.0
CATEGORIES=	www
MASTER_SITES=	http://download.cksource.com/${PORTNAME}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/
DISTNAME=	ckeditor_${PORTVERSION}_full

MAINTAINER=	joehorn@gmail.com
COMMENT=	WYSIWYG editor to be used inside web page

LICENSE=	MPL

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/ckeditor

NO_STAGE=	yes
do-install:
	@${INSTALL} -d -m 0755 ${WWWDIR}
	@(cd ${WRKSRC} && ${FIND} . | ${CPIO} -pdmu -R${WWWOWN}:${WWWGRP} ${WWWDIR})

.include <bsd.port.mk>
