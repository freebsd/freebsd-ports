PORTNAME=	iosevka
DISTVERSIONPREFIX=	v
DISTVERSION=	7.2.3
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/be5invis/Iosevka/releases/download/${DISTVERSIONFULL}/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Slender monospace sans-serif and slab-serif typeface for programming

# The license file is not downloaded.
LICENSE=	OFL11

USES=		fonts zip

FONTNAME=	Iosevka

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

_STYLES=\
	DEFAULT		-		Monospace,\ Default\
	SLAB		-slab-		Monospace,\ Slab\
	CURLY		-curly-		Monospace,\ Curly\
	CURLYSLAB	-curly-slab-	Monospace,\ Curly\ Slab\
	ANDALE		-ss01-		Monospace,\ Andale\ Mono\ Style\
	ANONYMOUS	-ss02-		Monospace,\ Anonymous\ Pro\ Style\
	CONSOLAS	-ss03-		Monospace,\ Consolas\ Style\
	MENLO		-ss04-		Monospace,\ Menlo\ Style\
	FIRAMONO	-ss05-		Monospace,\ Fira\ Mono\ Style\
	LIBERATIONMONO	-ss06-		Monospace,\ Liberation\ Mono\ Style\
	MONACO		-ss07-		Monospace,\ Monaco\ Style\
	PRAGMATAPRO	-ss08-		Monospace,\ Pragmata\ Pro\ Style\
	SOURCECODEPRO	-ss09-		Monospace,\ Source\ Code\ Pro\ Style\
	ENVYCODER	-ss10-		Monospace,\ Envy\ Code\ R\ Style\
	XWINDOWSFIXED	-ss11-		Monospace,\ X\ Windows\ Fixed\ Style\
	UBUNTUMONO	-ss12-		Monospace,\ Ubuntu\ Mono\ Style\
	LUCIDA		-ss13-		Monospace,\ Lucida\ Style\
	JETBRAINSMONO	-ss14-		Monospace,\ JetBrains\ Mono\ Style\
	IMBPLEXMONO	-ss15-		Monospace,\ IMB\ Plex\ Mono\ Style\
	PTMONO		-ss16-		Monospace,\ PT\ Mono\ Style\
	RECURSIVEMONO	-ss17-		Monospace,\ Recursive\ Mono\ Style\
	INPUTMONO	-ss18-		Monospace,\ Input\ Mono\ Style\
	AILE		-aile-		Quasi-proportional,\ Sans-serif\ (Aile)\
	ETOILE		-etoile-	Quasi-proportional,\ Slab-serif\ (Etoile)\

.for name variant desc in ${_STYLES}
OPTIONS_DEFINE+=		${name}_STYLE
OPTIONS_DEFAULT+=		${name}_STYLE

${name}_STYLE_DESC=		${desc:S/\\ / /g}
${name}_STYLE_DISTFILES=	super-ttc-${PORTNAME}${variant}${DISTVERSION}${EXTRACT_SUFX}
${name}_STYLE_PLIST_FILES=	${FONTSDIR}/${PORTNAME}${variant:S/-$//}.ttc

post-install-${name}_STYLE-on:
	${INSTALL_DATA} ${WRKSRC}/${${name}_STYLE_PLIST_FILES:S|^${FONTSDIR}/||} ${STAGEDIR}${FONTSDIR}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
