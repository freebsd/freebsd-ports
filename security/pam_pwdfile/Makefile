PORTNAME=	pam_pwdfile
PORTVERSION=	1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Pam module for authenticating with flat passwd files

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	tiwe-de
GH_PROJECT=	libpam-pwdfile

MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	lib/pam_pwdfile.so
PORTDOCS=	README INSTALL
CFLAGS+=	-I${WRKSRC}

OPTIONS_DEFINE=	DOCS

post-patch:
#	${REINPLACE_CMD} -e 's|#include <features.h>||g' ${WRKSRC}/pam_pwdfile.c
	${CP} ${FILESDIR}/_pam_macros.h ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
