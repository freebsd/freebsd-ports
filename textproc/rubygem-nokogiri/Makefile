# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	rubygem-pkg-config>=1.1.7:devel/rubygem-pkg-config
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

CONFIGURE_ARGS=	--use-system-libraries
USE_GNOME=	libxml2 libxslt
USE_RUBY=	yes
USES=		gem gnome pkgconfig

PLIST_FILES=	bin/nokogiri

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -name '*.o' -o -name '*.so' | ${XARGS} ${STRIP_CMD}
	${RMDIR} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ports/

.include <bsd.port.mk>
