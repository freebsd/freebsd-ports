PORTNAME=	medusa
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.foofus.net/~jmk/tools/

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Speedy, massively parallel, modular, login brute-forcer

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libssh2.so:security/libssh2

USES=	ssl

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-module-ncp=no --enable-module-afp=no
CFLAGS+=	-fcommon

OPTIONS_DEFINE=	DOCS PGSQL SUBVERSION
OPTIONS_SUB=	yes

SUBVERSION_LIB_DEPENDS=	libsvn_client-1.so:devel/subversion
SUBVERSION_CFLAGS=	-I${LOCALBASE}/include/subversion-1 -I${LOCALBASE}/include/apr-1
SUBVERSION_CONFIGURE_OFF=	--enable-module-svn=no

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
