# $FreeBSD$

PORTNAME=	rbnacl-libsodium
PORTVERSION=	1.0.13
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	idefix@fechner.net
COMMENT=	Port rbnacl with bundled libsodium

LICENSE=	MIT

BUILD_DEPENDS=	rubygem-bundler>=1.5:sysutils/rubygem-bundler \
		rubygem-rake>=10:devel/rubygem-rake
RUN_DEPENDS=	rubygem-rbnacl>=3.0.1:security/rubygem-rbnacl

USES=		gem libtool
USE_LDCONFIG=	yes
USE_RUBY=	yes

post-install:
	( cd ${WRKSRC} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${GEMS_DIR}/${PORTNAME}-${PORTVERSION} )
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/vendor/libsodium/src/libsodium/.libs/libsodium.so.18.3.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/vendor/libsodium/dist/lib/libsodium.so.18.3.0

.include <bsd.port.mk>
