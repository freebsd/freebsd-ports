# New ports collection makefile for:   ftimes
# Date created:		20 August 2002
# Whom:			Klayton Monroe <klm@uidzero.org>
#
# $FreeBSD$
#

PORTNAME=		ftimes
PORTVERSION=		3.3.0
CATEGORIES=		security sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ftimes
EXTRACT_SUFX=		.tgz

MAINTAINER=		klm@uidzero.org
COMMENT=		A system baselining and evidence collection tool

GNU_CONFIGURE=		YES
USE_REINPLACE=		YES

.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--without-ssl
.else
USE_OPENSSL=		YES
CONFIGURE_ARGS+=	--with-ssl=${OPENSSLBASE}
.endif

.if defined(NO_STATIC)
CFLAGS+=
.else
CFLAGS+=		-static
.endif

MAN1=			ftimes.1

post-patch:
	${REINPLACE_CMD} -e "s,-O2,${CFLAGS},g" ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${PREFIX}/bin/ftimes

.include <bsd.port.mk>
