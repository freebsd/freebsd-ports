# New ports collection makefile for:	tinymce
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	tinymce
PORTVERSION=	3.3.6
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/TinyMCE/${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	An open source Javascript HTML WYSIWYG editor for web sites

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL} -d -m 0755 ${WWWDIR}
	@(cd ${WRKSRC} && ${FIND} . | ${CPIO} -pdmu -R${WWWOWN}:${WWWGRP} ${WWWDIR})

.include <bsd.port.mk>
