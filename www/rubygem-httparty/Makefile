PORTNAME=	httparty
PORTVERSION=	0.20.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Library that Makes HTTP Fun Again

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-mime-types>=3.0:misc/rubygem-mime-types \
		rubygem-multi_xml>=0.5.2:textproc/rubygem-multi_xml

USES=		cpe gem
CPE_VENDOR=	john_nunemaker
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/httparty

.include <bsd.port.mk>
