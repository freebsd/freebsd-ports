# New ports collection makefile for:	webjob
# Date created:		20 August 2002
# Whom:			Klayton Monroe <klm@uidzero.org>
#
# $FreeBSD$
#

PORTNAME=		webjob
PORTVERSION=		1.6.0
CATEGORIES=		sysutils security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webjob
EXTRACT_SUFX=		.tgz

MAINTAINER=		klm@uidzero.org
COMMENT=		Download and execute a program over HTTP/HTTPS

GNU_CONFIGURE=		YES

.if defined(WITHOUT_PAD)
PLIST_SUB+=		PAD="@comment "
.else
PLIST_SUB+=		PAD=""
CONFIGURE_ARGS+=	--with-pad-tools
.endif

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--without-ssl
.else
USE_OPENSSL=		YES
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.if defined(WITHOUT_DSV) # Note: DSV requires SSL
PLIST_SUB+=		DSV="@comment "
.else
PLIST_SUB+=		DSV=""
CONFIGURE_ARGS+=	--with-dsv-tools
MAN1+=			webjob-dsvtool.1
.endif
.endif

.if !defined(NO_STATIC)
CFLAGS+=		-static
.endif

MAN1+=			webjob.1

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/webjob

.include <bsd.port.mk>
