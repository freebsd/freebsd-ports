# New ports collection makefile for:  akpop3d
# Date created:        Sun Apr  6 10:12:16 CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	akpop3d
PORTVERSION=	0.7.7
PORTREVISION=	0
CATEGORIES=	mail
MASTER_SITES=	http://www.synflood.at/akpop3d/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 daemon aimed to be small and secure

MAN8=		akpop3d.8
PLIST_FILES=	bin/akpop3d

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

.if defined(WITH_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
CONFIGURE_ENV=	CPPFLAGS="-I${OPENSSLBASE}/include"
LDFLAGS+=	-L${OPENSSLBASE}/lib -lssl -lcrypto
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/akpop3d ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/akpop3d.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
