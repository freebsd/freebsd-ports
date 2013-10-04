# $FreeBSD$

PORTNAME=	libexttextcat
PORTVERSION=	3.4.3
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/libexttextcat/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Language guessing by N-Gram-Based Text Categorization

LICENSE=	BSD

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XZ=		yes
USES=		gmake pathfix

MAKE_ARGS=	EXEEXT=x

PORTDOCS=	README README.libtextcat TODO

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

check:
	cd ${WRKSRC}/src && make check

.include <bsd.port.mk>
