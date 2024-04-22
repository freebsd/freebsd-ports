PORTNAME=	ua
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finds sets of identical files
WWW=		https://github.com/euedge/ua/wiki

LICENSE=	MPL11

USES=		autoreconf ssl
USE_CXXSTD=	c++14
USE_GITHUB=	yes
GH_ACCOUNT=	euedge
GH_TAGNAME=	7a35148

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PLIST_FILES=	bin/kua bin/ua \
		share/man/man1/kua.1.gz share/man/man1/ua.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
