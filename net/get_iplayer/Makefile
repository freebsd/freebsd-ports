# $FreeBSD$

PORTNAME=	get_iplayer
PORTVERSION=	2.83
PORTREVISION=	1
CATEGORIES=	net multimedia
MASTER_SITES=	ftp://ftp.infradead.org/pub/${PORTNAME}/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Search, index, or stream archive video from BBC iPlayer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rtmpdump:${PORTSDIR}/multimedia/rtmpdump \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-HTTP-Cookies>=0:${PORTSDIR}/www/p5-HTTP-Cookies

USE_PERL5_RUN=	yes
NO_BUILD=	yes

USE_RC_SUBR=	${PORTNAME}

USERS=		get_iplayer
GROUPS=		get_iplayer

MAN1=		get_iplayer.1

SCRIPTS=	${PORTNAME} ${PORTNAME}.cgi
PLIST_FILES=	bin/${PORTNAME} ${SCRIPTS:S,^,${WWWDIR_REL}/,}

DATADIR=	${WWWDIR}
PORTDATA=	html plugins

PORTDOCS=	CHANGELOG-get_iplayer.cgi.txt CHANGELOG.txt \
		README-get_iplayer.cgi.txt README.md web.sh

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e "s|/usr/bin/get_iplayer|${PREFIX}/bin/${PORTNAME}|" \
		${WRKSRC}/README-get_iplayer.cgi.txt ${WRKSRC}/get_iplayer.cgi
	${REINPLACE_CMD} -e "s|/usr/bin/|${LOCALBASE}/bin|" \
		${WRKSRC}/README-get_iplayer.cgi.txt
	${REINPLACE_CMD} -e "s|/usr/share/get_iplayer|${WWWDIR}|" \
		${WRKSRC}/get_iplayer

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${WWWDIR})
	${LN} -sf ${WWWDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.for DIR in html plugins
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${WWWDIR})
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

post-install:
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
