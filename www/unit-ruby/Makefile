# Created by: Sergey Osokin <osa@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-ruby${RUBY_VER}

COMMENT=	Ruby module for NGINX Unit

PLIST_FILES=	libexec/unit/modules/ruby${RUBY_VER}.unit.so

USE_RUBY=	yes

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	./configure ruby --module=ruby${RUBY_VER}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/ruby${RUBY_VER}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
