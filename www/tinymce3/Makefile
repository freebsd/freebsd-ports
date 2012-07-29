# New ports collection makefile for:	tinymce
# Date created:				26 Mar 2007
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	tinymce
PORTVERSION=	3.4.9
CATEGORIES=	www
MASTER_SITES=	http://cloud.github.com/downloads/${PORTNAME}/${PORTNAME}/ \
		LOCAL/sunpoet
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Open source JavaScript HTML WYSIWYG editor for web sites

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

#post-extract:
#	@${TOUCH} \
#		${WRKSRC}/jscripts/tiny_mce/plugins/spellchecker/classes/utils/.keepme \
#		${WRKSRC}/jscripts/tiny_mce/plugins/spellchecker/includes/.keepme

do-install:
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} . ${WWWDIR}/
	${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}/

.include <bsd.port.mk>
