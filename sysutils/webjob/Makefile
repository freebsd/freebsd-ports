# Created by: Klayton Monroe <klm@uidzero.org>
# $FreeBSD$

PORTNAME=	webjob
PORTVERSION=	1.9.0
PORTREVISION=	1
CATEGORIES=	sysutils security
MASTER_SITES=	SF

MAINTAINER=	klm@uidzero.org
COMMENT=	Download and execute a program over HTTP/HTTPS

BROKEN_aarch64=	fails to build: aarch64 is not currently supported
BROKEN_mips64=	fails to build: mips64 is not currently supported

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	tools/xshar/xshar
GNU_CONFIGURE=	yes
USE_PERL5=	build

OPTIONS_DEFINE=	PAD_TOOLS DSV_TOOLS SSL
OPTIONS_DEFAULT=	PAD_TOOLS DSV_TOOLS
PAD_TOOLS_DESC=	install PaD tools
DSV_TOOLS_DESC=	install DSV tools

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAD_TOOLS}
PLIST_SUB+=		PAD_TOOLS=""
CONFIGURE_ARGS+=	--with-pad-tools
.else
PLIST_SUB+=		PAD_TOOLS="@comment "
.endif

.if ! ${PORT_OPTIONS:MSSL}
CONFIGURE_ARGS+=	--without-ssl
PLIST_SUB+=		DSV_TOOLS="@comment "
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.if ! ${PORT_OPTIONS:MDSV_TOOLS} # Note: DSV requires SSL
PLIST_SUB+=		DSV_TOOLS="@comment "
.else
PLIST_SUB+=		DSV_TOOLS=""
CONFIGURE_ARGS+=	--with-dsv-tools
MAN1+=			webjob-dsvtool.1
.endif
.endif

.if !defined(NO_STATIC)
CFLAGS+=		-static
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/webjob

.include <bsd.port.mk>
