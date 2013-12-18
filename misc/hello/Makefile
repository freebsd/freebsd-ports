# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	hello
PORTVERSION=	2.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	hello

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A utility for saying hello to the world and reading email

USES=		charsetfix perl5
USE_PERL5=	build
GNU_CONFIGURE=	YES

MAN1=		hello.1
INFO=		hello

NO_STAGE=	yes
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
