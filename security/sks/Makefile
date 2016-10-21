# $FreeBSD$

PORTNAME=	sks
PORTVERSION=	1.1.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://bitbucket.org/skskeyserver/sks-keyserver/downloads/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Synchronizing Key Server, a fast OpenPGP keyserver

PROJECTHOST=	sks-keyserver

USE_OCAML=	yes
USE_OCAML_CAMLP4=yes
USES=		bdb:5 perl5 gmake shebangfix tar:tgz
USE_PERL5=	build
MAKE_JOBS_UNSAFE=yes
SHEBANG_FILES=	sks_build.sh

MAKE_ENV=	BDBINCLUDE="-I${BDB_INCLUDE_DIR}" \
		BDBLIB="-L${BDB_LIB_DIR}" \
		LIBDB="-l${BDB_LIB_NAME}" \
		MANDIR="${MANPREFIX}/man"

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-extract:
	@: > ${WRKSRC}/Makefile.local
	@${REINPLACE_CMD} 's/-ccopt -pg //' ${WRKSRC}/Makefile
	@cd ${WRKSRC} && ${RM} .depend

post-patch:
	@${REINPLACE_CMD} -Ee '/^CC=/d; /^CFLAGS=/s/=/+=/' \
		-e '/^install/,$$s/\$$\((PREFIX|MANDIR)\)/$$(DESTDIR)&/' \
		-e '/patch/s/-p 0/-p0/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e '/^CC=/d; /^CFLAGS=/s/=/+=/' ${WRKSRC}/bdb/Makefile

pre-build:
	@cd ${WRKSRC} && test -f .depend || ${MAKE_CMD} dep

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} BUGS README.md TODO UPGRADING \
		 ${STAGEDIR}${DOCSDIR}
	@cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} sks sks_add_mail

.include <bsd.port.mk>
