# New ports collection makefile for:	medusa
# Date created:		2006-05-01
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	medusa
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.foofus.net/jmk/tools/ \
		http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A speedy, massively parallel, modular, login brute-forcer

OPTIONS=	SVN "Enable Subversion module" off \
		POSTGRESQL "Enable PostgreSQL module" off

LIB_DEPENDS+=	ssh2:${PORTSDIR}/security/libssh2 \
		pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-module-ncp=no --enable-module-afp=no

MAN1=		medusa.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not build on ia64
.endif

.if defined(WITH_SVN)
PLIST_SUB+=	SVN=""
LIB_DEPENDS+=	svn_client-1:${PORTSDIR}/devel/subversion \
		apr-1:${PORTSDIR}/devel/apr
CFLAGS+=	-I${LOCALBASE}/include/subversion-1 -I${LOCALBASE}/include/apr-1
.else
CONFIGURE_ARGS+=	--enable-module-svn=no
PLIST_SUB+=	SVN="@comment "
.endif

.if defined(WITH_POSTGRESQL)
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

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
