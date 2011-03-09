# Ports collection Makefile for:	get_iplayer
# Date created:				2nd March 2011
# Whom:					Chris Rees <utisoft@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	get_iplayer
PORTVERSION=	2.79
CATEGORIES=	net multimedia
MASTER_SITES=	ftp://ftp.infradead.org/pub/${PORTNAME}/ \
		http://www.bayofrum.net/dist/${PORTNAME}/
PKGNAMEPREFIX=	uk-

MAINTAINER=	utisoft@gmail.com
COMMENT=	Search, index, or stream archive video from BBC iPlayer

RUN_DEPENDS=	flvstreamer:${PORTSDIR}/multimedia/flvstreamer

USE_PERL5_RUN=	5.8.0+
NO_BUILD=	yes

USE_RC_SUBR=	${PORTNAME}

USERS  =	get_iplayer
GROUPS =	get_iplayer

MAN1=	get_iplayer.1

SCRIPTS=	${PORTNAME} ${PORTNAME}.cgi
PLIST_FILES=	bin/${PORTNAME} ${SCRIPTS:C,^,${WWWDIR_REL}/,}

.if !defined(NOPORTDATA)
DATADIR=	${WWWDIR}
PORTDATA=	html plugins
.else
PLIST_DIRS=	${WWWDIR_REL}
.endif

.if !defined(NOPORTDOCS)
PORTDOCS=	CHANGELOG-get_iplayer.cgi.txt CHANGELOG.txt \
		README-get_iplayer.cgi.txt README.txt web.sh
.endif

post-patch:
	${REINPLACE_CMD} -e "s|/usr/bin/get_iplayer|${PREFIX}/bin/${PORTNAME}|" \
		${WRKSRC}/README-get_iplayer.cgi.txt ${WRKSRC}/get_iplayer.cgi
	${REINPLACE_CMD} -e "s|/usr/bin/|${LOCALBASE}/bin|" \
		${WRKSRC}/README-get_iplayer.cgi.txt
	${REINPLACE_CMD} -e "s|/usr/share/get_iplayer|${WWWDIR}|" \
		${WRKSRC}/get_iplayer

do-install:
	@${MKDIR} ${WWWDIR}
	@(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${WWWDIR})
	@${LN} -sf ${WWWDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDATA)
.for DIR in html plugins
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${DIR} ${WWWDIR})
.endfor
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif

post-install:
	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
