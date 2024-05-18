PORTNAME=	get_iplayer
DISTVERSIONPREFIX=	v
DISTVERSION=	3.35
CATEGORIES=	multimedia net

MAINTAINER=	jamie@catflap.org
COMMENT=	Lists and records BBC iPlayer TV and BBC Sounds radio programmes
WWW=		https://github.com/get-iplayer/get_iplayer

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
USE_RC_SUBR=	${PORTNAME}

SHEBANG_FILES=	${PORTNAME} ${PORTNAME}.cgi

DATADIR=	${WWWDIR}
NO_ARCH=	yes
NO_BUILD=	yes

USERS=		get_iplayer
GROUPS=		get_iplayer

SCRIPTS=	${PORTNAME} ${PORTNAME}.cgi
PLIST_FILES=	bin/${PORTNAME} ${SCRIPTS:S,^,${WWWDIR_REL}/,} \
		share/man/man1/${PORTNAME}.1.gz

PORTDOCS=	CHANGELOG.md README.md

OPTIONS_DEFINE=			ATOMICPARSLEY DOCS FFMPEG
OPTIONS_DEFAULT=		ATOMICPARSLEY FFMPEG
ATOMICPARSLEY_DESC=		Enable tagging of media files
FFMPEG_DESC=			Enable file conversion using FFmpeg
ATOMICPARSLEY_RUN_DEPENDS=	atomicparsley>=0:multimedia/atomicparsley
FFMPEG_RUN_DEPENDS=		ffmpeg>=0:multimedia/ffmpeg

post-patch:
	${REINPLACE_CMD} -e "108,110c\\${.newline}	\$$opt_cmdline->{getiplayer} = \"${PREFIX}/bin/${PORTNAME}\";" \
		${WRKSRC}/get_iplayer.cgi

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${WWWDIR})
	${LN} -sf ${WWWDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
