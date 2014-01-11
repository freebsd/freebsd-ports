# $FreeBSD$

PORTNAME=	sks
PORTVERSION=	1.1.4
CATEGORIES=	security
MASTER_SITES=	http://cdn.bitbucket.org/skskeyserver/sks-keyserver/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Synchronizing Key Server, a fast OpenPGP keyserver

PROJECTHOST=	sks-keyserver

USE_OCAML=	yes
USE_BDB=	5
USES=		perl5 gmake shebangfix
USE_PERL5=	build
MAKE_JOBS_UNSAFE=yes
SHEBANG_FILES=	sks_build.sh

MAKE_ENV=	BDBINCLUDE="-I${BDB_INCLUDE_DIR}" \
		BDBLIB="-L${BDB_LIB_DIR}" \
		LIBDB="-l${BDB_LIB_NAME}" \
		MANDIR="${MANPREFIX}/man"

SUB_FILES=	pkg-message

post-extract:
	@: > ${WRKSRC}/Makefile.local
	@${REINPLACE_CMD} 's/-ccopt -pg //' ${WRKSRC}/Makefile
	@cd ${WRKSRC} && ${RM} -f .depend

pre-build:
	@cd ${WRKSRC} && test -f .depend || ${GMAKE} dep

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} BUGS README.md TODO UPGRADING \
		 ${STAGEDIR}${DOCSDIR}
	@cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} sks sks_add_mail

.include <bsd.port.mk>
