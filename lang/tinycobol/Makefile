# New ports collection makefile for:	tinycobol
# Date created:		26 Oct 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tinycobol
PORTVERSION=	0.64
CATEGORIES=	lang
MASTER_SITES=	SF/tiny-cobol

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiny COBOL compiler for IA32 platforms

BROKEN=		Missing htcobol compiler binary
DEPRECATED=		no longer being developed; consider using lang/open-cobol instead
EXPIRATION_DATE=	2009-07-28

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes
USE_BDB=	3
USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-cobf2f \
		--with-libdb=3 \
		--with-readline
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

MANCOMPRESSED=	yes
MAN1=		htcobf2f.1 htcobol.1 htcobrun.1

CPPFLAGS=	-I${BDB_INCLUDE_DIR} -I${LOCALBASE}/include
LDFLAGS=	-L${BDB_LIB_DIR} -L${LOCALBASE}/lib

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e \
		'/^INSTALL_PROGRAM=/s|=.*|=@INSTALL_PROGRAM@|g ; \
		 /cobdir_docdir/s|^|#|g'

post-install:
	@(cd ${WRKSRC}/lib && ${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} \
		install-static-libs install-shared-libs)
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/info/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/info/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
