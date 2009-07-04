# New ports collection makefile for:	claws-mail-themes
# Date created:		2008-10-04
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	claws-mail-themes
PORTVERSION=	20090605
CATEGORIES=	x11-themes mail
MASTER_SITES=	http://www.claws-mail.org/themes/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Claws-Mail Themes

NO_BUILD=	yes

THEMESDIR?=	${PREFIX}/share/claws-mail/themes

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${THEMESDIR}
	    cd ${WRKSRC}/ && ${FIND} . -mindepth 2 -print | \
		${GREP} -vE '(Makefile.*|INSTALL)' | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${THEMESDIR}
	@${CHMOD} -R a+r ${THEMESDIR}
	@${FIND} ${THEMESDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${THEMESDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644

.include <bsd.port.post.mk>
