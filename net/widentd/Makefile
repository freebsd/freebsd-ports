PORTNAME=	widentd
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.05
CATEGORIES=	net
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	RFC1413 auth/identd daemon providing a fixed fake reply
WWW=		https://codeberg.org/BSDforge/widentd

LICENSE=	BSD3CLAUSE

USES=		ncurses uidfix

USE_RC_SUBR=	widentd

OPTIONS_DEFINE=	DOCS

MAKE_ENV=	BINDIR="${PREFIX}/sbin" MANDIR="${PREFIX}/share/man/man"
PLIST_FILES=	sbin/widentd share/man/man8/widentd.8.gz
PORTDOCS=	LICENSE README README.md

# else ports framework can't handle USE_RC_SUBR
post-extract:
	${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
