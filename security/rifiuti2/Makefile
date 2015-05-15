# Created by: antoine@FreeBSD.org
# $FreeBSD$

PORTNAME=	rifiuti2
PORTVERSION=	0.6.0
CATEGORIES=	security
MASTER_SITES=	https://github.com/abelcheung/rifiuti2/releases/download/${PORTVERSION}/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Tool for analyzing Windows recycle bin

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/docs/LICENSE

GNU_CONFIGURE=	yes
USES=		gettext gmake pkgconfig tar:xz
USE_GNOME=	glib20

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

PLIST_FILES=	bin/rifiuti \
		bin/rifiuti-vista \
		man/man1/rifiuti.1.gz \
		man/man1/rifiuti-vista.1.gz \
		share/locale/zh_HK/LC_MESSAGES/rifiuti.mo
PORTDOCS=	NEWS.md README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
