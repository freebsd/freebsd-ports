# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	arirang
PORTVERSION=	2.03
PORTEPOCH=	1
CATEGORIES=	security www
MASTER_SITES=	http://monkey.org/~pilot/arirang/
MASTER_SITE_SUBDIR=	UNIX/cgi-scanners

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Powerful webserver security scanner for network

LICENSE=	BSD

USE_RUBY=	1.8+
USE_RUBY_EXTCONF=	yes
USE_LIBRUBY=	yes

USE_OPENSSL=	yes

CFLAGS+=	-I${LOCALBASE}/include/ruby-${RUBY_VER} -I${LOCALBASE}/include/ruby-${RUBY_VER}/${RUBY_ARCH}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arirang ${STAGEDIR}${PREFIX}/sbin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/arirang
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/share/arirang
	${INSTALL_DATA} ${WRKSRC}/scanrule/*.uxe ${STAGEDIR}${PREFIX}/share/arirang
	${INSTALL_DATA} ${WRKSRC}/script/*.rb ${STAGEDIR}${PREFIX}/share/arirang

.include <bsd.port.mk>
