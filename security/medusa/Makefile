# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	medusa
PORTVERSION=	2.1.1
CATEGORIES=	security
MASTER_SITES=	http://www.foofus.net/~jmk/tools/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Speedy, massively parallel, modular, login brute-forcer

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2

BROKEN_ia64=	Does not build on ia64

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-module-ncp=no --enable-module-afp=no

OPTIONS_DEFINE=	SVN PGSQL DOCS
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSVN}
LIB_DEPENDS+=	libsvn_client-1.so:${PORTSDIR}/devel/subversion
CFLAGS+=	-I${LOCALBASE}/include/subversion-1 -I${LOCALBASE}/include/apr-1
.else
CONFIGURE_ARGS+=	--enable-module-svn=no
.endif

.if ${PORT_OPTIONS:MPGSQL}
USES+=		pgsql
CONFIGURE_ARGS+=	--enable-module-postgres
.else
CONFIGURE_ARGS+=	--enable-module-postgres=no
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_medusa \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_medusa

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
