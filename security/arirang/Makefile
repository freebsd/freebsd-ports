# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	arirang
PORTVERSION=	2.03
PORTEPOCH=	1
CATEGORIES=	security www
MASTER_SITES=	http://monkey.org/~pilot/arirang/
MASTER_SITE_SUBDIR=	UNIX/cgi-scanners

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful webserver security scanner for network

LICENSE=	BSD3CLAUSE

USE_RUBY=	yes
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

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 2.0
BROKEN=		Does not build with Ruby 2.0 or newer
.endif
DEPRECATED=	Does not work with Ruby 2.x
EXPIRATION_DATE=	2015-03-28

.include <bsd.port.post.mk>
