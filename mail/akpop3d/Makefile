# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	akpop3d
PORTVERSION=	0.7.7
CATEGORIES=	mail
MASTER_SITES=	http://www.synflood.at/akpop3d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 daemon aimed to be small and secure

MAN8=		akpop3d.8
PLIST_FILES=	bin/akpop3d

USE_BZIP2=	yes
GNU_CONFIGURE=	yes

.if defined(WITH_SSL)
USE_OPENSSL=	YES
CONFIGURE_ARGS+=--with-openssl=${OPENSSLBASE}
CPPFLAGS+=	-I${OPENSSLBASE}/include
LDFLAGS+=	-L${OPENSSLBASE}/lib -lssl -lcrypto
.endif

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/akpop3d ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/akpop3d.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
