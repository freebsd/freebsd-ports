# New ports collection makefile for:	mod_ntlm
# Date created:	   04 July 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	mod_ntlm
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	modntlm

MAINTAINER=	skv@FreeBSD.org
COMMENT=	NTLM authentication module for the Apache webserver

USE_APACHE=	YES
USE_REINPLACE=	YES
MAKE_ENV=	APXS=${APXS}

post-patch:
	${FIND} ${WRKSRC}/smbval -name "*.inc.c" -type f|${XARGS} \
		${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g"
	${REINPLACE_CMD} -e "s/APXS=.*//" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s!#include <sys/vfs.*!!" \
		${WRKSRC}/smbval/smbencrypt.inc.c

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/mod_ntlm.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
