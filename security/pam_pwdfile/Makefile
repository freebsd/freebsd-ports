PORTNAME=	pam_pwdfile
PORTVERSION=	2.0
MASTER_SITES=	https://git.tiwe.de/libpam-pwdfile.git/snapshot/
DISTFILES=	libpam-pwdfile-${PORTVERSION}.tar.gz
CATEGORIES=	security

MAINTAINER=	lev@FreeBSD.org
COMMENT=	Pam module for authenticating with flat passwd files
WWW=		https://www.cpbotha.net/software/pam_pwdfile/

LICENSE=	BSD3CLAUSE GPLv1 GPLv2 GPLv3
LICENSE_COMB=	dual

PLIST_FILES=	lib/pam_pwdfile.so
PORTDOCS=	README INSTALL
CFLAGS+=	-I${WRKSRC}

OPTIONS_DEFINE=	DOCS

MAKE_ARGS=	PAM_LIB_DIR=${PREFIX}/lib

WRKSRC=		${WRKDIR}/libpam-pwdfile-${PORTVERSION}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
