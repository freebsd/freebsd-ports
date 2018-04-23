# Created by: Sergey Osokin <osa@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-perl${PERL_VER}

COMMENT=	Perl module for NGINX Unit

PLIST_FILES=	libexec/unit/modules/perl${PERL_VER}.unit.so

USES=		perl5

USE_RC_SUBR?=	# reset to empty

MASTERDIR=	${.CURDIR}/../unit

post-configure:
	cd ${CONFIGURE_WRKSRC} && \
	./configure perl --module=perl${PERL_VER}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/unit/modules/
	${INSTALL_LIB} ${WRKSRC}/build/perl${PERL_VER}.unit.so \
		${STAGEDIR}${PREFIX}/libexec/unit/modules/

.include "${MASTERDIR}/Makefile"
