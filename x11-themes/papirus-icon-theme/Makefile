# $FreeBSD$

PORTNAME=	papirus-icon-theme
PORTVERSION=	20210302
CATEGORIES=	x11-themes

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Papirus icon theme

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake gnome
USE_GNOME=	gtk-update-icon-cache

USE_GITHUB=	yes
GH_ACCOUNT=	PapirusDevelopmentTeam

NO_ARCH=	yes
NO_BUILD=	yes

POST_PLIST=	add-plist-icon-cache
PORTDOCS=	AUTHORS README.md

OPTIONS_DEFINE=	DOCS

post-install:
	cd ${STAGEDIR}${PREFIX} && \
		${FIND} share/icons -type f -o -type l >> ${TMPPLIST}

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

add-plist-icon-cache:
# taken from Mk/Uses/gnome.mk gnome-post-icons
	for dir in `${GREP} "^share/icons/.*/" ${TMPPLIST} | \
			${CUT} -d / -f 1-3 | ${SORT} -u`; do \
		${ECHO_CMD} "@rmtry $${dir}/icon-theme.cache" >> ${TMPPLIST}; \
		${ECHO_CMD} "@postexec ${LOCALBASE}/bin/gtk-update-icon-cache \
			-q -f %D/$${dir} 2>/dev/null || /usr/bin/true" >> ${TMPPLIST}; \
		${ECHO_CMD} "@postunexec ${LOCALBASE}/bin/gtk-update-icon-cache \
			-q -f %D/$${dir} 2>/dev/null || /usr/bin/true" >> ${TMPPLIST}; \
	done

.include <bsd.port.mk>
