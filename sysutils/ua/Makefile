# $FreeBSD$

PORTNAME=	ua
PORTVERSION=	1.0.1
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finds sets of identical files

LICENSE=	MPL

USE_GITHUB=	yes
GH_ACCOUNT=	euedge
GH_TAGNAME=	7a35148

USES=		autoreconf ssl
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${OPENSSLLIB}
CFLAGS+=	-I${OPENSSLINC}

PLIST_FILES=	bin/kua bin/ua \
		man/man1/kua.1.gz man/man1/ua.1.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/*.1 ${STAGEDIR}${PREFIX}/man/man1/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
