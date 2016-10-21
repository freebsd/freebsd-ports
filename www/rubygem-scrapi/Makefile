# Created by: IWATSUKI Hiroyuki <don@na.rim.or.jp>
# $FreeBSD$

PORTNAME=	scrapi
PORTVERSION=	1.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	don@na.rim.or.jp
COMMENT=	ScrAPI toolkit for Ruby

BUILD_DEPENDS=	${LOCALBASE}/${SPEC_DIR}/tidy-1.1.2.gemspec:textproc/rubygem-tidy \
		tidy:www/tidy-lib

NO_ARCH=	yes

USE_RUBY=	yes
USE_LDCONFIG=	yes
USES=		gem
PLIST_FILES=	${GEM_LIB_DIR}/lib/tidy/libtidy.so

.include <bsd.port.pre.mk>

post-install:
	${RM} ${LOCALBASE}/${GEM_LIB_DIR}/lib/tidy/libtidy.dll
	${RM} ${LOCALBASE}/${GEM_LIB_DIR}/lib/tidy/libtidy.so
	${LN} -sf ${LOCALBASE}/lib/libtidy.so ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/lib/tidy/

.include <bsd.port.post.mk>
