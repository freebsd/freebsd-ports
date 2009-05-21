# New ports collection makefile for:	mod_ntlm
# Date created:	   04 July 2004
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	mod_ntlm
PORTVERSION=	0.4
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	modntlm

MAINTAINER=	skv@FreeBSD.org
COMMENT=	NTLM authentication module for the Apache webserver

MAKE_JOBS_SAFE=  yes

USE_APACHE=	1.3
MAKE_ENV=	APXS=${APXS}

.include <bsd.port.pre.mk>

post-patch:
	${FIND} ${WRKSRC}/smbval -name "*.inc.c" -type f|${XARGS} \
		${REINPLACE_CMD} -e "s/malloc.h/stdlib.h/g"
	${REINPLACE_CMD} -e "s/APXS=.*//" ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e "s!#include <sys/vfs.*!!" \
		${WRKSRC}/smbval/smbencrypt.inc.c
.if ${OSVERSION} >= 700042
	${REINPLACE_CMD} -e "s/extern/static/" ${WRKSRC}/smbval/smblib-priv.h
.endif

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/Documentation/mod_ntlm.html ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
