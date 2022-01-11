# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>

PORTNAME=	mechanize
PORTVERSION=	2.8.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	WWW::Mechanize, a handy web browsing ruby object

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-domain_name>=0.5.20190701<1:net/rubygem-domain_name \
		rubygem-http-cookie>=1.0.3<2:www/rubygem-http-cookie \
		rubygem-mime-types>=3.0<4:misc/rubygem-mime-types \
		rubygem-net-http-digest_auth>=1.4.1<2:www/rubygem-net-http-digest_auth \
		rubygem-net-http-persistent>=2.5.2<5.0:www/rubygem-net-http-persistent \
		rubygem-nokogiri>=1.11.2<2:textproc/rubygem-nokogiri \
		rubygem-rubyntlm>=0.6.3<1:net/rubygem-rubyntlm \
		rubygem-webrick>=1.7<2:www/rubygem-webrick \
		rubygem-webrobots>=0.1.2<0.2:www/rubygem-webrobots

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
