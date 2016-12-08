# Created by: Dennis Herrmann <adox@mcx2.org>
# $FreeBSD$

PORTNAME=	rss2html
PORTVERSION=	0.8.2
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://mirror.mcx2.org/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	RSS to HTML converter

LICENSE=	GPLv2

LIB_DEPENDS+=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
CFLAGS+=	"-I${LOCALBASE}/include" "-L${LOCALBASE}/lib"

PLIST_FILES=	bin/rss2html man/man1/rss2html.1.gz
PORTDOCS=	rss2html.links usage.example rss2html.template

post-patch:
	@${REINPLACE_CMD} -e '16,20d' ${WRKSRC}/Makefile.acr

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
