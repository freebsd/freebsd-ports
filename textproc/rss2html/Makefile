# New ports collection makefile for:	rss2html
# Date created:		2009-02-01
# Whom:			Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	rss2html
PORTVERSION=	0.8.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	RSS to HTML converter

LIB_DEPENDS+=	curl:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CFLAGS+=	"-I${LOCALBASE}/include" "-L${LOCALBASE}/lib"

MAN1=	rss2html.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/rss2html
PORTDOCS=	rss2html.links usage.example rss2html.template

post-patch:
	@${REINPLACE_CMD} -e '16,20d' ${WRKSRC}/Makefile.acr

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
