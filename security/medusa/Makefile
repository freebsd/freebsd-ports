# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	medusa
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.foofus.net/~jmk/tools/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Speedy, massively parallel, modular, login brute-forcer

OPTIONS_DEFINE=	SVN PGSQL DOCS

LIB_DEPENDS+=	ssh2:${PORTSDIR}/security/libssh2 \
		pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-module-ncp=no --enable-module-afp=no

MAN1=		medusa.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

.if ${PORT_OPTIONS:MSVN}
PLIST_SUB+=	SVN=""
LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion
CFLAGS+=	-I${LOCALBASE}/include/subversion-1 -I${LOCALBASE}/include/apr-1
.else
CONFIGURE_ARGS+=	--enable-module-svn=no
PLIST_SUB+=	SVN="@comment "
.endif

.if ${PORT_OPTIONS:MPGSQL}
PLIST_SUB+=	POSTGRESQL=""
USE_PGSQL=	yes
CONFIGURE_ARGS+=	--enable-module-postgres
.else
CONFIGURE_ARGS+=	--enable-module-postgres=no
PLIST_SUB+=	POSTGRESQL="@comment "
.endif

post-install:
	${MKDIR} ${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_medusa ${PREFIX}/share/zsh/site-functions/_medusa

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
