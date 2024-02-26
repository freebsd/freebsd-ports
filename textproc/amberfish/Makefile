PORTNAME=	amberfish
PORTVERSION=	1.6.4
PORTREVISION=	2
CATEGORIES=	textproc databases
MASTER_SITES=	SF/${PORTNAME}/Amberfish%20source%20-%20stable/${PORTVERSION}	\
		http://etymon.com/software/amberfish/stable/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose text retrieval Software
WWW=		https://web.archive.org/web/20100419215307/http://www.etymon.com/tr.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxerces-c.so:textproc/xerces-c3

USES=		gmake

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

ALL_TARGET=	all html

PLIST_FILES=	bin/af
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_USES=	makeinfo
DOCS_PLIST_FILES=	share/man/man1/af.1.gz

post-extract:
	${CP} ${FILESDIR}/porter.cc ${WRKSRC}/src

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${MAKEFLAGS} ||' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|cp |$${BSD_INSTALL_MAN} |' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-O3 |@CFLAGS@ | ; \
		s|make strip|| ; \
		s|cp |$${BSD_INSTALL_PROGRAM} |' ${WRKSRC}/src/Makefile.in

post-patch-DOCS-off:
	@${REINPLACE_CMD} -e \
		'/cd doc/d' ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/amberfish.png ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
