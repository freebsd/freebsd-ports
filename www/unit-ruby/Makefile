# Created by: Sergey Osokin <osa@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	3
PKGNAMESUFFIX=	-${UNIT_MODNAME}

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
	${CONFIGURE_CMD} ruby --module=${UNIT_MODNAME}

do-build:
	cd ${CONFIGURE_WRKSRC} && ${MAKE} ${UNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/${UNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
