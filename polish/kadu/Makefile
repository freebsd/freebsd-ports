# Ports collection makefile for:   kadu
# Date created:        17 July 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$
#

PORTNAME=		kadu
PORTVERSION=		0.6.5.2
PORTEPOCH=		1
CATEGORIES=		polish net-im
MASTER_SITES=		http://www.kadu.net/download/stable/:kadu \
			http://www.kadu.net/download/additions/:additions \
			http://www.kadu.net/download/modules_extra/spellchecker/:aspell \
			http://www.kadu.net/download/modules_mirror/:modules \
			http://kadu.net/~arvenil/tabs/download/${PORTVERSION:C/(([0-9]+\.){2}[0-9]+)(.*)/\1/}/:modtab
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:kadu
DIST_SUBDIR=		kadu
EXTRACT_ONLY=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		mwisnicki+freebsd@gmail.com
COMMENT=		QT Gadu-Gadu client

BUILD_DEPENDS=		bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=		gadu.3:${PORTSDIR}/polish/libgadu \
			qca.2:${PORTSDIR}/devel/qca \
			sndfile.1:${PORTSDIR}/audio/libsndfile
RUN_DEPENDS=		qca-ossl>=2.0.0.b3:${PORTSDIR}/security/qca-ossl
# TODO enable devel/libexecinfo

TABS_MOD_DISTFILE=	kadu-tabs-1.2.3.tar.bz2
ASPELL_MOD_DISTFILE=	spellchecker-20080821.tar.bz2

GG6_EMOTS_DISTFILE=	kompatybilne_z_GG6.tar.gz
GG7_EMOTS_DISTFILE=	dodatkowe_emoty_GG7.tar.gz

USE_BZIP2=		yes
USE_CMAKE=		yes
CMAKE_ARGS=		-DENABLE_AUTODOWNLOAD:BOOL=OFF
CMAKE_USE_PTHREAD=	yes

USE_QT_VER=		4
QT_COMPONENTS=		gui dbus linguist network qt3support webkit xml \
			qmake_build moc_build rcc_build uic_build
WANT_GNOME=		yes
INSTALLS_ICONS=		yes

WRKSRC=			${WRKDIR}/${PORTNAME}

OPTIONS=	AO	"Build AO sound module"		off \
		ASPELL	"Build spell checking module"	off \
		ARTS	"Build aRts sound module"	off \
		GG_EMOTS	"Install GG-compatible emoticons"	off \
		TABS	"Build tabs module"		off

.include <bsd.port.pre.mk>

.if defined(WITH_AO)
LIB_DEPENDS+=	ao.3:${PORTSDIR}/audio/libao
PLIST_SUB+=	AO_SOUND_MOD=""
KADU_SHARED_MODULES+=	ao_sound
.else
PLIST_SUB+=	AO_SOUND_MOD="@comment "
.endif

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	aspell.16:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL_MOD=""
DISTFILES+=	${ASPELL_MOD_DISTFILE}:aspell
KADU_SHARED_MODULES+=	spellchecker
.else
PLIST_SUB+=	ASPELL_MOD="@comment "
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS_MOD=""
KADU_SHARED_MODULES+=	arts_sound
.else
PLIST_SUB+=	ARTS_MOD="@comment "
.endif

.if defined(WITH_GG_EMOTS)
PLIST_SUB+=	GG_EMOTS=""
DISTFILES+=	${GG6_EMOTS_DISTFILE}:additions \
		${GG7_EMOTS_DISTFILE}:additions
.else
PLIST_SUB+=	GG_EMOTS="@comment "
.endif

.if defined(WITH_TABS)
PLIST_SUB+=	TABS_MOD=""
DISTFILES+=	${TABS_MOD_DISTFILE}:modtab
KADU_SHARED_MODULES+=	tabs
.else
PLIST_SUB+=	TABS_MOD="@comment "
.endif

KADU_DISABLED_MODULES=	alsa_sound

post-patch:
	@${FIND} ${WRKSRC} -exec ${GREP} -q "#!/bin/bash" {} \; \
		-exec ${REINPLACE_CMD} -e 's|#!/bin/bash|#!/usr/bin/env bash|g' {} \;
.for module in ${KADU_DISABLED_MODULES}
	@${REINPLACE_CMD} -e 's|module_${module}=.|module_${module}=n|g' ${WRKSRC}/.config
.endfor
.for module in ${KADU_SHARED_MODULES}
	@${REINPLACE_CMD} -e 's|module_${module}=.|module_${module}=m|g' ${WRKSRC}/.config
.endfor
.for module in ${KADU_STATIC_MODULES}
	@${REINPLACE_CMD} -e 's|module_${module}=.|module_${module}=y|g' ${WRKSRC}/.config
.endfor
.if defined(WITH_ASPELL)
	@cd ${WRKSRC}/modules && ${TAR} -zxf ${_DISTDIR}/${ASPELL_MOD_DISTFILE}
.endif
.if defined(WITH_GG_EMOTS)
	@${REINPLACE_CMD} -e 's|emoticons_gg6_compatible=n|emoticons_gg6_compatible=y|g' ${WRKSRC}/.config
	@cd ${WRKSRC}/varia/themes/emoticons && \
	${TAR} -zxf ${_DISTDIR}/${GG6_EMOTS_DISTFILE} && \
	${MV} kompatybilne_z_GG6 gg6_compatible && \
	cd gg6_compatible && ${TAR} -zxf ${_DISTDIR}/${GG7_EMOTS_DISTFILE}
.endif
.if defined(WITH_TABS)
	@cd ${WRKSRC}/modules && ${TAR} -zxf ${_DISTDIR}/${TABS_MOD_DISTFILE}
.endif

.include <bsd.port.post.mk>
