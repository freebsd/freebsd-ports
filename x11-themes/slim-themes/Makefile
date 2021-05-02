# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>

PORTNAME=	slim-themes
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11-themes
MASTER_SITES=	http://dist.codelabs.ru/fbsd/ports/slim-themes/:new_themes \
		http://dist.codelabs.ru/fbsd/ports/slim-themes/:old_themes \
		SF/slim.berlios/:old_themes
DISTFILES=

MAINTAINER=	d.oriented@gmail.com
COMMENT=	Theme pack for SLiM login app

RUN_DEPENDS=	slim>=0:x11/slim

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SHAREMODE=	644
THEMEDIR_REL=	share/slim/themes
THEMEDIR=	${PREFIX}/${THEMEDIR_REL}
PLIST_SUB+=	THEMEDIR=${THEMEDIR_REL}

OPTIONS_DEFINE=	# empty
OPTIONS_MULTI=	THEME	# enforces at least one choice
OPTIONS_SUB=	yes
THEME_DESC=	Available SLiM Themes

# Format is 'variable name%description%archive name%unpacked dir%dest
# dir%master site tag'
# I am substituting ' ' -> '+' because make in 6.x isn't able to properly
# catch quoted strings with spaces.  7.x and 8.x are fine with this, so
# once 6.x will be deorbited, we could switch just to spaces.
THEMELIST=	GENTOO_SIMPLE%Gentoo+simple+theme%slim-gentoo-simple.tar.bz2%slim-gentoo-simple%gentoo-simple%old_themes \
		ARCHLINUX_SIMPLE%ArchLinux+simple+theme%slim-archlinux-simple.tar.gz%slim-archlinux-simple%archlinux-simple%old_themes \
		DEBIAN_MOREBLUE%Debian+moreblue+theme%slim-debian-moreblue.tar.bz2%debian-moreblue%debian-moreblue%old_themes \
		FINGERPRINT%Fingerprint+theme%slim-fingerprint.tar.gz%fingerprint%fingerprint%old_themes \
		FLAT%Flat+theme%slim-flat.tar.gz%flat%flat%old_themes \
		LAKE%Lake+theme%slim-lake.tar.gz%lake%lake%old_themes \
		RAINBOW%Rainbow+theme%slim-rainbow.tar.gz%rainbow%rainbow%old_themes \
		REAR_WINDOW%Rear+Window+theme%slim-rear-window.tar.gz%rear-window%rear-window%old_themes \
		SCOTLAND_ROAD%Scotland+Road+theme%slim-scotland-road.tar.gz%scotland-road%scotland-road%old_themes \
		SUBWAY%Subway+theme%slim-subway.tar.gz%subway%subway%old_themes \
		WAVE%Wave+theme%slim-wave.tar.gz%wave%wave%old_themes \
		LUNAR_LINUX%Lunar+Linux+theme%slim-lunar-0.4.tar.bz2%slim-lunar-0.4%lunar%old_themes \
		ZENWALK%Zenwalk+theme%slim-zenwalk.tar.gz%Zenwalk%zenwalk%old_themes \
		PARALLEL_DIMS%Parallel+Dimensions+theme%slim-parallel-dimensions.tar.gz%parallel-dimensions%parallel-dimensions%old_themes \
		CAPERNOITED%Capernoited+theme%slim-capernoited.tar.gz%capernoited%capernoited%old_themes \
		MINDLOCK%Mindlock+theme%slim-mindlock.tar.gz%mindlock%mindlock%old_themes \
		FLOWER2%Flower2+theme%slim-flower2.tar.gz%flower2%flower2%old_themes \
		FREEBSD%FreeBSD+theme%fbsd-slim-theme.tar.bz2%fbsd%fbsd%new_themes \
		GNEWSENSE%gNewSense+theme%slim-gnewsense-1.1.tar.bz2%slim-gnewsense-1.1%gnewsense%new_themes

# Pollute OPTIONS and DISTFILES.  Cool magic ;))
# We're using immediate assignment and two variables, because there is
# no addition (+=) operator with immediate assignment.

.for t in ${THEMELIST}
n=	${t:C/^([^%]*)%.*$/\\1/1}
d=	${t:C/^[^%]*%[^%]*%([^%]*)%.*$/\\1/1}
desc=	${t:C/^[^%]*%([^%]*)%.*$/\\1/1:C/\+/ /g}
sdir=	${t:C/^[^%]*%[^%]*%[^%]*%([^%]*)%.*$/\\1/1}
ddir=	${t:C/^[^%]*%[^%]*%[^%]*%[^%]*%([^%]*)%.*$/\\1/1}
mtag=	${t:C/^[^%]*%[^%]*%[^%]*%[^%]*%[^%]*%([^%]*)$/\\1/1}
.if ${mtag} == ""
${n}_DIST:=	${d}
.else
${n}_DIST:=	${d}:${mtag}
.endif
${n}_SDIR:=	${sdir}
${n}_DDIR:=	${ddir}
OPTIONS_MULTI_THEME:=	${OPTIONS_MULTI_THEME} ${n}
A+=		${n}
${n}_DESC:=	${desc}
NEWTHEMES:=	${ALLTHEMES}	${n}
ALLTHEMES:=	${NEWTHEMES}
.endfor # t in ${THEMELIST}

OPTIONS_DEFAULT=	${OPTIONS_MULTI_THEME}

.include <bsd.port.options.mk>

.for n in ${ALLTHEMES}
.  if ${PORT_OPTIONS:M${n}}
NEWDISTFILES:=	${DISTFILES}	${${n}_DIST}
DISTFILES:=	${NEWDISTFILES}
.  endif
.endfor

.if ${PORT_OPTIONS:MPARALLEL_DIMS}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-parallel-dimensions-slim.theme

post-patch:
	@${RM} ${WRKSRC}/parallel-dimensions/slim.theme.orig
.endif # ${PORT_OPTIONS:MPARALLEL_DIMS}

# Install selected themes.  Another regexp voodoo, yay! \o/
do-install:
	${MKDIR} ${STAGEDIR}${THEMEDIR}
.for n in ${ALLTHEMES}
.if ${PORT_OPTIONS:M${n}}
	${MKDIR} ${STAGEDIR}${THEMEDIR}/${${n}_DDIR}
	cd "${WRKSRC}/${${n}_SDIR}" && \
	  ${COPYTREE_SHARE} . ${STAGEDIR}${THEMEDIR}/${${n}_DDIR}
.endif # ${PORT_OPTIONS:M${n}}
.endfor # t in ${THEMELIST}

.include <bsd.port.mk>
