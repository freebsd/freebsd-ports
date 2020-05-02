# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	akpop3d
PORTVERSION=	0.7.7
CATEGORIES=	mail
MASTER_SITES=	https://synflood.at/akpop3d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	POP3 daemon aimed to be small and secure

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/akpop3d man/man8/akpop3d.8.gz

OPTIONS_DEFINE=		SSL
OPTIONS_DEFAULT=	SSL

SSL_USES=	ssl
SSL_CONFIGURE_WITH=	openssl=${OPENSSLBASE}
SSL_CPPFLAGS=	-I${OPENSSLBASE}/include
SSL_LDFLAGS=	-L${OPENSSLBASE}/lib

USE_RC_SUBR=	akpop3d

pre-patch:
	@${REINPLACE_CMD} -e "s,STRLCPY_h,STRLCPY_H," ${WRKSRC}/strlcpy.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/akpop3d ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/akpop3d.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
