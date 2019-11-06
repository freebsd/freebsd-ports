# $FreeBSD$

PORTNAME=	ftwin
PORTVERSION=	0.8.8
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://files.etoilebsd.net/ftwin/ \
		http://download.meroware.org/ftwin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful tool to find duplicate files

BROKEN=		unfetchable

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libpcre.so:devel/pcre \
		libpuzzle.so:graphics/libpuzzle

USES=		autoreconf libarchive tar:bzip2
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS EXAMPLES TODO CHANGES KNOWN_BUGS VERSION README
PLIST_FILES=	bin/ftwin man/man8/ftwin.8.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Werror -g -ggdb|| ; \
		 s|-O0||' ${WRKSRC}/Makefile.am

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
