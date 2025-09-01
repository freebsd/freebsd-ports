PORTNAME=	marmite
DISTVERSION=	0.2.6
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	dutra@FreeBSD.org
COMMENT=	Static site generator
WWW=		https://github.com/rochacbruno/marmite

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo ssl pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	rochacbruno

PORTEXAMPLES=	*

OPTIONS_DEFINE=	EXAMPLES
EXAMPLES_DESC=	Build example site

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	@cd ${WRKSRC}/example && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
