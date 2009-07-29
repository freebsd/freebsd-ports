# New ports collection makefile for:	OSSP uuid
# Date created:				12 February 2004
# Whom:					Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	uuid
PORTVERSION=	1.6.2
PORTREVISION=	1
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	vd@FreeBSD.org
COMMENT=	ISO-C & Perl API and CLI for generating Universally Unique Identifiers

CONFLICTS=	e2fsprogs-libuuid-[0-9]*

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-shared --enable-static --with-cxx

MAN1=	uuid-config.1 uuid.1
MAN3=	uuid.3 uuid++.3

.if defined(WITH_PERL)
USE_PERL5=	5.8.0+
CONFIGURE_ENV+=	PERL=${PERL5}
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=	WITH_PERL=''
MAN3=		OSSP::uuid.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
.else
PLIST_SUB+=	WITH_PERL='@comment '
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

regression-test: test

test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
