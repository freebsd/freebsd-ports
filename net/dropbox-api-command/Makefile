# Created by: Lung-Pin Chang <changlp@cs.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	dropbox-api-command
PORTVERSION=	2.10
PORTEPOCH=	1
CATEGORIES=	net perl5

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Dropbox API wrapper command

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	p5-DateTime-Format-Strptime>=0:devel/p5-DateTime-Format-Strptime \
		p5-Encode-Locale>=0:converters/p5-Encode-Locale \
		p5-JSON>=0:converters/p5-JSON \
		p5-Path-Class>=0.26:devel/p5-Path-Class \
		p5-WebService-Dropbox>=2.05:net/p5-WebService-Dropbox
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	s-aska

NO_ARCH=	yes
USES=		perl5 shebangfix
USE_PERL5=	modbuildtiny
bash_CMD=	${SH}
SHEBANG_FILES=	script/upload-to-dropbox

.include <bsd.port.mk>
