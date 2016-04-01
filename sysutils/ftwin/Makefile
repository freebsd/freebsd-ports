# $FreeBSD$

PORTNAME=	ftwin
PORTVERSION=	0.8.8
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://files.etoilebsd.net/ftwin/ \
		http://download.meroware.org/ftwin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful tool to find duplicate files

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libapr-1.so:devel/apr1 \
		libpcre.so:devel/pcre \
		libpuzzle.so:graphics/libpuzzle

USES=		autoreconf libarchive tar:bzip2
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS EXAMPLES TODO CHANGES KNOWN_BUGS VERSION README
PLIST_FILES=	bin/ftwin man/man8/ftwin.8.gz

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-Werror -g -ggdb|| ; \
		 s|-O0||' ${WRKSRC}/Makefile.am

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor

.include <bsd.port.mk>
