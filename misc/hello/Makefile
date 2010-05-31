# New ports collection makefile for:	hello
# Date created:				Fri Jul 23, 1999
# Whom:					shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	hello
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	hello

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A utility for saying hello to the world and reading email

USE_PERL5_BUILD=	YES
GNU_CONFIGURE=	YES

MAN1=		hello.1
INFO=		hello

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-install:
	${CHMOD} a+x ${WRKSRC}/build-aux/install-sh

.include <bsd.port.mk>
