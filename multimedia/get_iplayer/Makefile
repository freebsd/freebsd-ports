# $FreeBSD$

PORTNAME=	get_iplayer
PORTVERSION=	3.27
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia net

MAINTAINER=	jamie@catflap.org
COMMENT=	Lists and records BBC iPlayer TV and BBC Sounds radio programmes.

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
OPTIONS_DEFAULT=	FFMPEG ATOMICPARSLEY
FFMPEG_DESC=	Enable file conversion using FFmpeg
FFMPEG_RUN_DEPENDS=	ffmpeg>=0:multimedia/ffmpeg
ATOMICPARSLEY_DESC=	Enable tagging of media files
ATOMICPARSLEY_RUN_DEPENDS=	AtomicParsley>=0:multimedia/atomicparsley

post-patch:
	${REINPLACE_CMD} -e "108,110c\\${.newline}	\$$opt_cmdline->{getiplayer} = \"${PREFIX}/bin/${PORTNAME}\";" \
		${WRKSRC}/get_iplayer.cgi

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC}; ${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${WWWDIR})
	${LN} -sf ${WWWDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
