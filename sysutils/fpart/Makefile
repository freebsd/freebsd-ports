PORTNAME=	fpart
PORTVERSION=	1.6.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://contribs.martymac.org/fpart/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Sort and pack files into partitions
WWW=		https://contribs.martymac.org

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--disable-embfts

PLIST_FILES=	bin/fpart share/man/man1/fpart.1.gz
PORTDOCS=	Changelog.md README.md TODO

OPTIONS_DEFINE=	FPSYNC DOCS
OPTIONS_DEFAULT=	FPSYNC
FPSYNC_DESC=	Install fpsync tool
FPSYNC_RUN_DEPENDS=	rsync:net/rsync \
			sudo:security/sudo
FPSYNC_PLIST_FILES=	bin/fpsync share/man/man1/fpsync.1.gz

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
