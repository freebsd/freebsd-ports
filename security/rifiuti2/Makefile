# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rifiuti2
DISTVERSION=	0.5.1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tool for analyzing Windows recycle bin

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USES=		gettext pkgconfig
USE_GNOME=	glib20

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/rifiuti \
		bin/rifiuti-vista \
		man/man1/rifiuti.1.gz \
		man/man1/rifiuti-vista.1.gz
PORTDOCS=	AUTHORS ChangeLog NEWS README THANKS TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
