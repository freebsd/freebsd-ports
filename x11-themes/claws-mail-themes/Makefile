# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	claws-mail-themes
PORTVERSION=	20120129
CATEGORIES=	x11-themes mail
MASTER_SITES=	http://www.claws-mail.org/themes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Claws-Mail Themes

NO_BUILD=	yes

THEMESDIR?=	${PREFIX}/share/claws-mail/themes

do-install:
	@${MKDIR} ${STAGEDIR}${THEMESDIR}
	    cd ${WRKSRC}/ && ${FIND} . -mindepth 2 -print | \
		${GREP} -vE '(Makefile.*|INSTALL)' | \
		${CPIO} -pdu -R ${BINOWN}:${BINGRP} --quiet ${STAGEDIR}${THEMESDIR}
	@${CHMOD} -R a+r ${STAGEDIR}${THEMESDIR}
	@${FIND} ${STAGEDIR}${THEMESDIR} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${STAGEDIR}${THEMESDIR} -type f -print0 | ${XARGS} -0 ${CHMOD} 644

.include <bsd.port.mk>
