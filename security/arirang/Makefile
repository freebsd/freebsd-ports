# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	arirang
PORTVERSION=	2.03
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	security www
MASTER_SITES=	http://monkey.org/~pilot/arirang/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful webserver security scanner for network

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	lib${RUBY_NAME}.so:${RUBY_PORT}

USES=		ssl
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CFLAGS+=	-I${LOCALBASE}/include/ruby-${RUBY_VER} -I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}
CFLAGS+=	-DRUBY_19
CFLAGS+=	-I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${STAGEDIR}${PREFIX}/sbin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/arirang
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${STAGEDIR}${PREFIX}/share/arirang
	${INSTALL_DATA} ${WRKSRC}/script/*.rb ${STAGEDIR}${PREFIX}/share/arirang

.include <bsd.port.mk>
