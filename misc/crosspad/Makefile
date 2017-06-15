# Created by: itojun@itojun.org
# $FreeBSD$

PORTNAME=	crosspad
PORTVERSION=	19991202
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.itojun.org/pub/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Crosspad data downloader/converter

USES=		ncurses perl5
USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_path_perl=${PERL}
WRKSRC=		${WRKDIR}/crosspad/build

PORTDOCS=	PROTOCOL README.english README.japanese

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E -e 's,(bin|man)dir),DESTDIR)$$(&,g' \
		-e 's,-(g|o) (bin|uucp),,g' \
		${WRKSRC}/Makefile.in

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/../|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
