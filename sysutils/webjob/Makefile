# New ports collection makefile for:	webjob
# Date created:		20 August 2002
# Whom:			Klayton Monroe <klm@uidzero.org>
#
# $FreeBSD$
#

PORTNAME=		webjob
PORTVERSION=		1.8.0
CATEGORIES=		sysutils security
MASTER_SITES=		SF
EXTRACT_SUFX=		.tgz

MAINTAINER=		klm@uidzero.org
COMMENT=		Download and execute a program over HTTP/HTTPS

GNU_CONFIGURE=		yes
USE_PERL5_BUILD=	yes
MAN1=			webjob.1 xshar.1

OPTIONS=		PAD_TOOLS "install PaD tools" on \
			DSV_TOOLS "install DSV tools" on

.include <bsd.port.pre.mk>

.if defined(WITH_PAD_TOOLS)
PLIST_SUB+=		PAD_TOOLS=""
CONFIGURE_ARGS+=	--with-pad-tools
.else
PLIST_SUB+=		PAD_TOOLS="@comment "
.endif

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--without-ssl
.else
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.if defined(WITHOUT_DSV_TOOLS) # Note: DSV requires SSL
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
	@${STRIP_CMD} ${PREFIX}/bin/webjob

.include <bsd.port.post.mk>
