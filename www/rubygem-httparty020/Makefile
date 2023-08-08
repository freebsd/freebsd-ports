PORTNAME=	httparty
PORTVERSION=	0.20.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	020

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Library that Makes HTTP Fun Again
WWW=		https://www.johnnunemaker.com/httparty/ \
		https://github.com/jnunemaker/httparty

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-mime-types>=3.0<4:misc/rubygem-mime-types \
		rubygem-multi_xml>=0.5.2:textproc/rubygem-multi_xml

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	john_nunemaker

PORTSCOUT=	limit:^0\.20\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/httparty

.include <bsd.port.mk>
