# $FreeBSD$

PORTNAME=	get_iplayer
PORTVERSION=	2.94
CATEGORIES=	net multimedia
MASTER_SITES=	ftp://ftp.infradead.org/pub/${PORTNAME}/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Search, index, or stream archive video from BBC iPlayer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTTP-Cookies>=0:www/p5-HTTP-Cookies \
		p5-HTTP-Message>=0:www/p5-HTTP-Message \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww \
		rtmpdump:multimedia/rtmpdump

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	${PORTNAME} ${PORTNAME}.cgi
NO_BUILD=	yes
NO_ARCH=	yes

USE_RC_SUBR=	${PORTNAME}

USERS=		get_iplayer
GROUPS=		get_iplayer

SCRIPTS=	${PORTNAME} ${PORTNAME}.cgi
PLIST_FILES=	bin/${PORTNAME} ${SCRIPTS:S,^,${WWWDIR_REL}/,} \
		man/man1/${PORTNAME}.1.gz

DATADIR=	${WWWDIR}
PORTDATA=	html plugins

PORTDOCS=	CHANGELOG-get_iplayer.cgi.txt CHANGELOG.txt \
		README-get_iplayer.cgi.txt README.md web.sh

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e "s|/usr/bin/get_iplayer|${PREFIX}/bin/${PORTNAME}|" \
		${WRKSRC}/README-get_iplayer.cgi.txt ${WRKSRC}/get_iplayer.cgi
	${REINPLACE_CMD} -e "s|/usr/bin/|${LOCALBASE}/bin|" \
		${WRKSRC}/README-get_iplayer.cgi.txt
	${REINPLACE_CMD} -e "s|/usr/share/get_iplayer|${WWWDIR}|" \
		${WRKSRC}/get_iplayer

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${WWWDIR})
	${LN} -sf ${WWWDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1
.for DIR in html plugins
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${STAGEDIR}${WWWDIR})
.endfor

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
