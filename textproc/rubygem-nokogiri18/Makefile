# $FreeBSD$

PORTNAME=	nokogiri
PORTVERSION=	1.8.5
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	18

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	HTML, XML, SAX, and Reader parser

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${RUN_DEPENDS}
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
RUN_DEPENDS=	rubygem-pkg-config>=1.1.7:devel/rubygem-pkg-config

USES=		gem gnome pkgconfig
USE_GNOME=	libxml2 libxslt
USE_RUBY=	yes

CONFIGURE_ARGS=	--use-system-libraries

PORTSCOUT=	limit:^1\.8\.

post-install:
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -name '*.o' -o -name '*.so' | ${XARGS} ${STRIP_CMD}
	${RM} ${STAGEDIR}${PREFIX}/bin/nokogiri
	${RMDIR} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ports/

.include <bsd.port.mk>
