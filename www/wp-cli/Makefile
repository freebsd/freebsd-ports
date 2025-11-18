PORTNAME=	wp-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	2.12.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/
PKGNAMESUFFIX=	${PHP_PKGNAMESUFFIX}
DISTFILES+=	${PORTNAME}-${DISTVERSION}.phar
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkaipila@gmail.com
COMMENT=	Command line interface for WordPress
WWW=		https://wp-cli.org/ \
		https://github.com/wp-cli/wp-cli/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		php:cli,flavors
USE_GITHUB=	yes
USE_PHP=	filter mbstring mysqli phar simplexml tokenizer xml xmlreader \
		xmlwriter zip zlib

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/wp \
		etc/bash_completion.d/wp.bash \
		share/fish/completions/wp.fish

do-install:
	${INSTALL_SCRIPT} ${DISTDIR}/${PORTNAME}-${DISTVERSION}.phar \
		${STAGEDIR}${PREFIX}/bin/wp
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d \
		 ${STAGEDIR}${PREFIX}/share/fish/completions
	${INSTALL_DATA} ${WRKSRC}/utils/wp-completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/wp.bash
	${INSTALL_DATA} ${WRKSRC}/utils/wp.fish \
		${STAGEDIR}${PREFIX}/share/fish/completions/wp.fish

.include <bsd.port.mk>
