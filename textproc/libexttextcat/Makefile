# $FreeBSD$

PORTNAME=	libexttextcat
PORTVERSION=	3.4.5
CATEGORIES=	textproc
MASTER_SITES=	https://dev-www.libreoffice.org/src/libexttextcat/

MAINTAINER=	office@FreeBSD.org
COMMENT=	Language guessing by N-Gram-Based Text Categorization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake libtool pathfix tar:xz

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
MAKE_ARGS=	EXEEXT=x
TEST_ARGS=	# empty
TEST_TARGET=	check
TEST_WRKSRC=	${WRKSRC}/src
USE_LDCONFIG=	yes

PORTDOCS=	README README.libtextcat TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
