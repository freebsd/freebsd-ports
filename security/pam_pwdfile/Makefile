# Created by: Michael Schout <mschout@gkg.net>
# $FreeBSD$

PORTNAME=	pam_pwdfile
PORTVERSION=	0.99
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://cpbotha.net/files/pam_pwdfile/

MAINTAINER=	mschout@gkg.net
COMMENT=	Pam module for authenticating with flat passwd files

USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	lib/pam_pwdfile.so
PORTDOCS=	README INSTALL changelog
CFLAGS+=	-I${WRKSRC}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|#include <features.h>||g' ${WRKSRC}/pam_pwdfile.c
	${CP} ${FILESDIR}/_pam_macros.h ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
