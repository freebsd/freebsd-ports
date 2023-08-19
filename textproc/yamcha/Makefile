PORTNAME=	yamcha
PORTVERSION=	0.33
PORTREVISION=	2
CATEGORIES=	textproc science
MASTER_SITES=	http://chasen.org/~taku/software/yamcha/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Multipurpose CHunk Annotator
WWW=		http://chasen.org/~taku/software/yamcha/

DEPRECATED=	Last upstream release was in 2005
EXPIRATION_DATE=	2023-09-30
BROKEN_FreeBSD_14=	fails to compile: no matching function for call to 'make_pair'

BUILD_DEPENDS=	svm_learn:science/svmlight

USES=		libtool perl5
USE_CXXSTD=	c++98
USE_LDCONFIG=	yes
USE_PERL5=	build

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

PORTDOCS=	feature.png feature2.png feature3.png \
		feature4.png feature5.png index.html \
		yamcha.html yamcha.css

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
