PKGNAMESUFFIX=	-${UNIT_MODNAME}

UNIT_MODNAME=	ruby${RUBY_VER}

COMMENT=	Ruby module for NGINX Unit

RUN_DEPENDS=	rackup:www/rubygem-rackup \
		unitd:www/unit

BROKEN_RUBY33=	checking for Ruby library ... not found

PLIST_FILES=	libexec/unit/modules/${UNIT_MODNAME}.unit.so

USES=	ruby

CFLAGS+=	-fdeclspec

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ruby \
		--ruby=ruby${RUBY_VER:S|.||} \
		--module=${UNIT_MODNAME}

do-build:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
			${MAKEFILE} ${MAKE_ARGS} ${UNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/lib/unit/modules/${UNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
