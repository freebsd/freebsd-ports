# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	medusa
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.foofus.net/~jmk/tools/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speedy, massively parallel, modular, login brute-forcer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libssh2.so:security/libssh2

BROKEN_ia64=	Does not build on ia64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-module-ncp=no --enable-module-afp=no

OPTIONS_DEFINE=	SVN PGSQL DOCS
OPTIONS_SUB=	yes

SVN_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion
SVN_CFLAGS=		-I${LOCALBASE}/include/subversion-1 -I${LOCALBASE}/include/apr-1
SVN_CONFIGURE_OFF=	--enable-module-svn=no

PGSQL_USES=		pgsql
PGSQL_CONFIGURE_ON=	--enable-module-postgres
PGSQL_CONFIGURE_OFF=	--enable-module-postgres=no

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_medusa \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_medusa

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
