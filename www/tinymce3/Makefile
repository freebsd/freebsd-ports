# New ports collection makefile for:	tinymce
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	tinymce
PORTVERSION=	3.3.9.3
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/${PORTNAME}/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	An open source Javascript HTML WYSIWYG editor for web sites

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL} -d -m 0755 ${WWWDIR}
	(cd ${WRKSRC} && ${FIND} . | ${CPIO} -pdmu -R${WWWOWN}:${WWWGRP} ${WWWDIR})

.include <bsd.port.mk>
