PORTNAME=	btor2tools
DISTVERSION=	g20320816
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Generic parser and tool package for the BTOR2 format
WWW=		https://github.com/Boolector/btor2tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cmake cpe
USE_LDCONFIG=	yes

CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	Boolector
GH_TAGNAME=	037f1fa

MAKEFILE=	makefile

PLIST_FILES=	bin/btorsim \
		bin/btorsplit \
		bin/catbtor \
		include/btor2parser.h \
		lib/libbtor2parser.so

do-test:
	@cd ${WRKSRC} && LD_PRELOAD=${WRKSRC}/build/libbtor2parser.so test/runtests.sh

.include <bsd.port.mk>
