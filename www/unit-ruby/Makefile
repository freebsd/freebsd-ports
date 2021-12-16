# Created by: Sergey Osokin <osa@FreeBSD.org>

PKGNAMESUFFIX=	-${UNIT_MODNAME}
PORTREVISION=	1

UNIT_MODNAME=	ruby${RUBY_VER}

COMMENT=	Ruby module for NGINX Unit

RUN_DEPENDS=	rackup:www/rubygem-rack \
		unitd:www/unit

PLIST_FILES=	libexec/unit/modules/${UNIT_MODNAME}.unit.so

USE_RUBY=	yes

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${SETENV} ${CONFIGURE_ENV} ${CONFIGURE_CMD} ruby \
		--module=${UNIT_MODNAME}

do-build:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
			${MAKEFILE} ${MAKE_ARGS} ${UNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/${UNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

# Overwrite the target in the ${MASTERDIR}/Makefile
post-install:
	@${DO_NADA}

.include "${MASTERDIR}/Makefile"
