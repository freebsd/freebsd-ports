# $FreeBSD$

PORTNAME=	libexttextcat
PORTVERSION=	3.4.5
CATEGORIES=	textproc
MASTER_SITES=	http://dev-www.libreoffice.org/src/libexttextcat/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Language guessing by N-Gram-Based Text Categorization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes
MAKE_ARGS=	EXEEXT=x
TEST_ARGS=	# empty
TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/src
USE_LDCONFIG=	yes
USES=		gmake libtool pathfix tar:xz
INSTALL_TARGET=	install-strip

PORTDOCS=	README README.libtextcat TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
