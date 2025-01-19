PORTNAME=	iosevka
DISTVERSIONPREFIX=	v
DISTVERSION=	32.4.0
CATEGORIES=	x11-fonts
MASTER_SITES=	https://github.com/be5invis/Iosevka/releases/download/${DISTVERSIONFULL}/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Slender monospace sans-serif and slab-serif typeface for programming
WWW=		https://typeof.net/Iosevka/

# The license file is not downloaded.
LICENSE=	OFL11

USES=		fonts zip

FONTNAME=	Iosevka

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

_STYLES=\
	DEFAULT		Iosevka			Monospace,\ Default\
	SLAB		IosevkaSlab		Monospace,\ Slab\
	CURLY		IosevkaCurly		Monospace,\ Curly\
	CURLYSLAB	IosevkaCurlySlab	Monospace,\ Curly\ Slab\
	ANDALE		IosevkaSS01		Monospace,\ Andale\ Mono\ Style\
	ANONYMOUS	IosevkaSS02		Monospace,\ Anonymous\ Pro\ Style\
	CONSOLAS	IosevkaSS03		Monospace,\ Consolas\ Style\
	MENLO		IosevkaSS04		Monospace,\ Menlo\ Style\
	FIRAMONO	IosevkaSS05		Monospace,\ Fira\ Mono\ Style\
	LIBERATIONMONO	IosevkaSS06		Monospace,\ Liberation\ Mono\ Style\
	MONACO		IosevkaSS07		Monospace,\ Monaco\ Style\
	PRAGMATAPRO	IosevkaSS08		Monospace,\ Pragmata\ Pro\ Style\
	SOURCECODEPRO	IosevkaSS09		Monospace,\ Source\ Code\ Pro\ Style\
	ENVYCODER	IosevkaSS10		Monospace,\ Envy\ Code\ R\ Style\
	XWINDOWSFIXED	IosevkaSS11		Monospace,\ X\ Windows\ Fixed\ Style\
	UBUNTUMONO	IosevkaSS12		Monospace,\ Ubuntu\ Mono\ Style\
	LUCIDA		IosevkaSS13		Monospace,\ Lucida\ Style\
	JETBRAINSMONO	IosevkaSS14		Monospace,\ JetBrains\ Mono\ Style\
	IMBPLEXMONO	IosevkaSS15		Monospace,\ IMB\ Plex\ Mono\ Style\
	PTMONO		IosevkaSS16		Monospace,\ PT\ Mono\ Style\
	RECURSIVEMONO	IosevkaSS17		Monospace,\ Recursive\ Mono\ Style\
	INPUTMONO	IosevkaSS18		Monospace,\ Input\ Mono\ Style\
	AILE		IosevkaAile		Quasi-proportional,\ Sans-serif\ (Aile)\
	ETOILE		IosevkaEtoile		Quasi-proportional,\ Slab-serif\ (Etoile)\

.for name variant desc in ${_STYLES}
OPTIONS_DEFINE+=		${name}_STYLE
OPTIONS_DEFAULT+=		${name}_STYLE

${name}_STYLE_DESC=		${desc:S/\\ / /g}
${name}_STYLE_DISTFILES=	SuperTTC-${variant}-${DISTVERSION}${EXTRACT_SUFX}
${name}_STYLE_PLIST_FILES=	${FONTSDIR}/${variant}.ttc

post-install-${name}_STYLE-on:
	${INSTALL_DATA} ${WRKSRC}/${variant}.ttc ${STAGEDIR}${FONTSDIR}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}

.include <bsd.port.mk>
