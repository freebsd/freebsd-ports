PORTNAME=	linguistics
PORTVERSION=	2.1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Framework for extending Ruby objects with linguistic methods

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-loggability>=0.11<1:textproc/rubygem-loggability

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	lib/linguistics.rb \
		lib/linguistics/en/linkparser.rb

.include <bsd.port.mk>
