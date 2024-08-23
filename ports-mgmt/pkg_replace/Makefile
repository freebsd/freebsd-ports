PORTNAME=	pkg_replace
DISTVERSION=	20240819
CATEGORIES=	ports-mgmt

MAINTAINER=	kdeguchi@sz.tokoha-u.ac.jp
COMMENT=	Utility for upgrading installed packages
WWW=		https://github.com/kdeguchi/pkg_replace

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	kdeguchi

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

PORTDOCS=	ChangeLog README README.ja

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|%%ETCDIR%%|${ETCDIR}|g;s|%%PKGCOMPATDIR%%|${PKGCOMPATDIR}|g' \
		${WRKSRC}/${PORTNAME}.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/sbin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}${ETCDIR}/${PORTNAME}.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
