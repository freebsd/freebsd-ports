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

PORTDOCS=	README README.libtextcat TODO

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

PLIST_SUB+=	EXEEXT='x'
MAKE_ARGS=	EXEEXT=x

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

check:
	cd ${WRKSRC}/src && make check

.include <bsd.port.mk>
