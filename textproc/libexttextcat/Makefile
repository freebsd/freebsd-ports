# $FreeBSD$

PORTNAME=	libexttextcat
PORTVERSION=	3.4.4
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/libexttextcat/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Language guessing by N-Gram-Based Text Categorization

LICENSE=	BSD3CLAUSE

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix tar:xz
INSTALL_TARGET=	install-strip

MAKE_ARGS=	EXEEXT=x

PORTDOCS=	README README.libtextcat TODO

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

check:
	cd ${WRKSRC}/src && make check

.include <bsd.port.mk>
