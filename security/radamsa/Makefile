# Created by: Jukka Ukkonen <jau@iki.fi>

PORTNAME=	radamsa
PORTVERSION=	0.5
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	jau@iki.fi
COMMENT=	General purpose fuzzer

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

BROKEN=		fails to build: runaway build
DEPRECATED=	Abandonware, last release in 2017 and marked as BROKEN in late 2020
EXPIRATION_DATE=2022-03-31

BUILD_DEPENDS=	ol:lang/owl-lisp

USE_GITHUB=	yes
GH_ACCOUNT=	aoh

PLIST_FILES=	bin/radamsa \
		man/man1/radamsa.1.gz

.include <bsd.port.mk>
