# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yamcha
PORTVERSION=	0.33
PORTREVISION=	2
CATEGORIES=	textproc science
MASTER_SITES=	http://chasen.org/~taku/software/yamcha/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Multipurpose CHunk Annotator

BUILD_DEPENDS=	svm_learn:science/svmlight

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool perl5
USE_PERL5=	build
INSTALL_TARGET=	install-strip
PORTDOCS=	feature.png feature2.png feature3.png \
		feature4.png feature5.png index.html \
		yamcha.html yamcha.css

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
