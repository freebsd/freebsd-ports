# Created by: Michael Schout <mschout@gkg.net>
# $FreeBSD$

PORTNAME=	pam_pwdfile
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://cpbotha.net/files/pam_pwdfile/

MAINTAINER=	mschout@gkg.net
COMMENT=	A pam module for authenticating with flat passwd files

MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	lib/pam_pwdfile.so
PORTDOCS=	README INSTALL changelog
CFLAGS+=	-I${WRKSRC}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|#include <features.h>||g' ${WRKSRC}/pam_pwdfile.c
	${CP} ${FILESDIR}/_pam_macros.h ${WRKSRC}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
