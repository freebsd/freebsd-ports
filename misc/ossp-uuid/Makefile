# New ports collection makefile for:   OSSP uuid
# Date created:                12 February 2004
# Whom:                        Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	uuid
PORTVERSION=	1.2.0
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO-C & Perl API and CLI for generating Universally Unique Identifiers

CONFLICTS=	e2fsprogs-[0-9]*

USE_LIBTOOL_VER=	15
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS+=	--disable-shared --enable-static

MAN1=		uuid-config.1 uuid.1
MAN3=		uuid.3

.if defined(WITH_PERL)
USE_PERL5=	yes
CONFIGURE_ENV+=	PERL=${PERL5}
CONFIGURE_ARGS+=	--with-perl
PLIST_SUB+=		WITH_PERL=''
MAN3=			OSSP::uuid.3
MAN3PREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}
.else
PLIST_SUB+=		WITH_PERL='@comment '
.endif

test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.pre.mk>

.if defined(WITH_PERL) && ${PERL_LEVEL} < 500800
IGNORE=	supports Perl 5.8.0 or above only
.endif

.include <bsd.port.post.mk>
