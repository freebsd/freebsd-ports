PORTNAME=	haml
PORTVERSION=	7.4.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Elegant, structured (X)HTML/XML templating engine
WWW=		https://haml.info/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-prism>=1.1.0:textproc/rubygem-prism \
		rubygem-temple>=0.8.0:devel/rubygem-temple \
		rubygem-thor>=0:devel/rubygem-thor \
		rubygem-tilt>=0:devel/rubygem-tilt

USES=		cpe gem shebangfix

NO_ARCH=	yes

PLIST_FILES=	bin/haml

SHEBANG_FILES=	bin/*

.include <bsd.port.mk>
