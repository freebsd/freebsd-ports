PORTNAME=	httparty
PORTVERSION=	0.23.2
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Library that Makes HTTP Fun Again
WWW=		https://www.johnnunemaker.com/httparty/ \
		https://github.com/jnunemaker/httparty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-csv>=0:devel/rubygem-csv \
		rubygem-mini_mime>=1.0.0:mail/rubygem-mini_mime \
		rubygem-multi_xml>=0.5.2:textproc/rubygem-multi_xml

USES=		cpe gem

NO_ARCH=	yes

PLIST_FILES=	bin/httparty

CPE_VENDOR=	john_nunemaker

.include <bsd.port.mk>
