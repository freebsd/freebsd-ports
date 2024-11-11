PORTNAME=	oil
DISTVERSIONPREFIX=	v
DISTVERSION=	0.24.0
CATEGORIES=	shells
MASTER_SITES=	https://www.oilshell.org/download/
PKGNAMESUFFIX=	-shell
DISTNAME=	oils-for-unix-${PORTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	New Unix shell
WWW=		https://www.oilshell.org/ \
		https://github.com/oils-for-unix/oils

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/oils-for-unix \
		bin/osh \
		bin/ysh \
		share/man/man1/osh.1.gz

do-build:
	@cd ${WRKSRC} && \
		${SETENV} ${MAKE_ENV} _build/oils.sh
do-install:
	@cd ${WRKSRC} && \
		${SETENV} DESTDIR=${STAGEDIR} ./install

.include <bsd.port.mk>
