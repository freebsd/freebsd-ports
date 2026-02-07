PORTNAME=	gepub
PORTVERSION=	1.0.15
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Ruby generic EPUB parser/generator
WWW=		https://github.com/skoji/gepub

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-nokogiri>=1.8.2<2.0:textproc/rubygem-nokogiri \
		rubygem-rubyzip>=1.1.1<2.5:archivers/rubygem-rubyzip

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/genepub \
		bin/gepuber

.include <bsd.port.mk>
