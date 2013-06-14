# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	hello
PORTVERSION=	2.8
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	hello

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A utility for saying hello to the world and reading email

USE_PERL5_BUILD=	YES
GNU_CONFIGURE=	YES
USES=		charsetfix

MAN1=		hello.1
INFO=		hello

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

pre-install:
	${CHMOD} a+x ${WRKSRC}/build-aux/install-sh

.include <bsd.port.mk>
