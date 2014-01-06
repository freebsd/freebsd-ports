# $FreeBSD$

PORTNAME=	ftwin
PORTVERSION=	0.8.8
CATEGORIES=	sysutils
MASTER_SITES=	http://files.etoilebsd.net/ftwin/ \
		http://download.meroware.org/ftwin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Useful tool to find duplicate files

LICENSE=	APACHE20

LIB_DEPENDS=	libapr-1.so:${PORTSDIR}/devel/apr1 \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libpuzzle.so:${PORTSDIR}/graphics/libpuzzle

OPTIONS_DEFINE=	DOCS

USE_BZIP2=	yes
USE_AUTOTOOLS=	aclocal autoheader automake autoconf
AUTOMAKE_ARGS=	--add-missing

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	AUTHORS EXAMPLES TODO CHANGES KNOWN_BUGS VERSION README
PLIST_FILES=	bin/ftwin man/man8/ftwin.8.gz

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
