# $FreeBSD$

PORTNAME=	get_iplayer
PORTVERSION=	3.24
DISTVERSIONPREFIX=v
CATEGORIES=	net multimedia

MAINTAINER=	jamie@catflap.org
COMMENT=	Search, index, or stream archive video from BBC iPlayer

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-Mojolicious>=0:www/p5-Mojolicious \
		p5-LWP-Protocol-https>=0:www/p5-LWP-Protocol-https \
		p5-CGI>=0:www/p5-CGI

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	get-iplayer
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
PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=	DOCS FFMPEG ATOMICPARSLEY
FFMPEG_DESC=	Enable file conversion using FFmpeg
FFMPEG_RUN_DEPENDS=	ffmpeg>=0:multimedia/ffmpeg
ATOMICPARSLEY_DESC=	Enable tagging of media files
ATOMICPARSLEY_RUN_DEPENDS=	AtomicParsley>=0:multimedia/atomicparsley

post-patch:
	${REINPLACE_CMD} -e "s|/usr/bin/get_iplayer|${PREFIX}/bin/${PORTNAME}|" \
		${WRKSRC}/README.md ${WRKSRC}/get_iplayer.cgi
	${REINPLACE_CMD} -e "s|/usr/bin/|${LOCALBASE}/bin|" \
		${WRKSRC}/README.md
	${REINPLACE_CMD} -e "s|/usr/share/get_iplayer|${WWWDIR}|" \
		${WRKSRC}/get_iplayer

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${WWWDIR})
	${LN} -sf ${WWWDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
