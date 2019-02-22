# $FreeBSD$

PORTNAME=	cld3
DISTVERSION=	3.2.2
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Compact Language Detection for Ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	protobuf>0:devel/protobuf \
		rubygem-ffi>0:devel/rubygem-ffi

USES=		gem pkgconfig
USE_RUBY=	yes

## do-install here to prevent removal of ext
do-install:
	(cd ${BUILD_WRKSRC}; ${SETENV} ${GEM_ENV} ${RUBYGEMBIN} install \
		${RUBYGEM_ARGS} ${GEMFILES} -- ${CONFIGURE_ARGS})
	${RM} -r ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR}/build_info/
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -type f -name '*.so' \
		-exec ${STRIP_CMD} {} +
	${FIND} ${STAGEDIR}${PREFIX}/${GEMS_BASE_DIR} -type f \
		\( -name mkmf.log -or -name gem_make.out \) -delete
	${RM} -r ${STAGEDIR}${PREFIX}/${CACHE_DIR} 2> /dev/null || ${TRUE}
	${RMDIR} ${STAGEDIR}${PREFIX}/${DOC_DIR} 2> /dev/null || ${TRUE}
	${RMDIR} ${STAGEDIR}${PREFIX}/${EXT_DIR} 2> /dev/null || ${TRUE}

.include <bsd.port.mk>
