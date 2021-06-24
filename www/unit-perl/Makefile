# Created by: Sergey Osokin <osa@FreeBSD.org>

PKGNAMESUFFIX=	-${UNIT_MODNAME}

UNIT_MODNAME=	perl${PERL_VER}

COMMENT=	Perl module for NGINX Unit

PLIST_FILES=	libexec/unit/modules/${UNIT_MODNAME}.unit.so

RUN_DEPENDS=	unitd:www/unit

USES=		perl5

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

# Fix build failure on clang12
.if ${OSVERSION} >= 1400023
CFLAGS+=	-Wno-compound-token-split-by-macro
.endif

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	${CONFIGURE_CMD} perl --module=${UNIT_MODNAME}

do-build:
	cd ${CONFIGURE_WRKSRC} && ${MAKE} ${UNIT_MODNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/${UNIT_MODNAME}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

# Overwrite the target in the ${MASTERDIR}/Makefile
post-install:
	@${DO_NADA}

.include "${MASTERDIR}/Makefile"
