# Created by: Sergey Osokin <osa@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-${UNIT_MODNAME}

UNIT_MODNAME=	perl${PERL_VER}

COMMENT=	Perl module for NGINX Unit

PLIST_FILES=	libexec/unit/modules/${UNIT_MODNAME}.unit.so

RUN_DEPENDS=	unitd:www/unit

USES=		perl5

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${CONFIGURE_CMD} perl --module=${UNIT_MODNAME}

do-build:
	cd ${CONFIGURE_WRKSRC} && ${MAKE} ${UNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/${UNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
