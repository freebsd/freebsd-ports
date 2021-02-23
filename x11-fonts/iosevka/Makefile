# $FreeBSD$

PORTNAME=	iosevka
DISTVERSIONPREFIX=	v
DISTVERSION=	5.0.3
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
	DEFAULT		yes	-		Monospace,\ Default\
	SLAB		yes	-slab-		Monospace,\ Slab\
	CURLY		yes	-curly-		Monospace,\ Curly\
	CURLYSLAB	yes	-curly-slab-	Monospace,\ Curly\ Slab\
	ANDALE		yes	-ss01-		Monospace,\ Andale\ Mono\ Style\
	ANONYMOUS	yes	-ss02-		Monospace,\ Anonymous\ Pro\ Style\
	CONSOLAS	yes	-ss03-		Monospace,\ Consolas\ Style\
	MENLO		yes	-ss04-		Monospace,\ Menlo\ Style\
	FIRAMONO	yes	-ss05-		Monospace,\ Fira\ Mono\ Style\
	LIBERATIONMONO	yes	-ss06-		Monospace,\ Liberation\ Mono\ Style\
	MONACO		yes	-ss07-		Monospace,\ Monaco\ Style\
	PRAGMATAPRO	yes	-ss08-		Monospace,\ Pragmata\ Pro\ Style\
	SOURCECODEPRO	yes	-ss09-		Monospace,\ Source\ Code\ Pro\ Style\
	ENVYCODER	yes	-ss10-		Monospace,\ Envy\ Code\ R\ Style\
	XWINDOWSFIXED	yes	-ss11-		Monospace,\ X\ Windows\ Fixed\ Style\
	UBUNTUMONO	yes	-ss12-		Monospace,\ Ubuntu\ Mono\ Style\
	LUCIDA		yes	-ss13-		Monospace,\ Lucida\ Style\
	JETBRAINSMONO	yes	-ss14-		Monospace,\ JetBrains\ Mono\ Style\
	IMBPLEXMONO	yes	-ss15-		Monospace,\ IMB\ Plex\ Mono\ Style\
	PTMONO		yes	-ss16-		Monospace,\ PT\ Mono\ Style\
	RECURSIVEMONO	yes	-ss17-		Monospace,\ Recursive\ Mono\ Style\
	AILE		no	-aile-		Quasi-proportional,\ Sans-serif\ (Aile)\
	ETOILE		no	-etoile-	Quasi-proportional,\ Slab-serif\ (Etoile)\

.for name has_spacing_variants variant_id desc in ${_STYLES}
option_variant_spacing_list:=	${name}_STYLE ${variant_id} default
.	if ${has_spacing_variants} == yes
option_variant_spacing_list+=	${name}_FIXED_STYLE -fixed${variant_id} fixed
option_variant_spacing_list+=	${name}_TERM_STYLE -term${variant_id} terminal
.	endif

.	for option variant spacing in ${option_variant_spacing_list}
OPTIONS_DEFINE+=	${option}
OPTIONS_DEFAULT+=	${option}

${option}_DESC=		${desc:S/\\ / /g}
.		if ${has_spacing_variants} == yes
${option}_DESC+=	(${spacing} spacing)
.		endif

${option}_DISTFILES=	ttf-${PORTNAME}${variant}${DISTVERSION}${EXTRACT_SUFX}

post-install-${option}-on:
	cd ${WRKSRC} && \
	${FIND} -E * -regex '${PORTNAME}${variant}[a-z]+[.]ttf' | \
	${XARGS} -J {} ${INSTALL_DATA} {} ${STAGEDIR}${FONTSDIR}

_regenerate-plist: _regenerate-plist-${option}

_regenerate-plist-${option}: patch _remove-pkg-plist.tmp
	cd ${WRKSRC} && \
	${FIND} -E * -regex '${PORTNAME}${variant}[a-z]+[.]ttf' | \
	${XARGS} ${PRINTF} '%%%%${option}%%%%%%%%FONTSDIR%%%%/%s\n' >> ${WRKDIR}/.pkg-plist.tmp
.	endfor
.endfor

OPTIONS_SUB=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}

_regenerate-plist:
	${SORT} -o ${.CURDIR}/pkg-plist ${WRKDIR}/.pkg-plist.tmp

_remove-pkg-plist.tmp:
	${RM} ${WRKDIR}/.pkg-plist.tmp

.include <bsd.port.mk>
