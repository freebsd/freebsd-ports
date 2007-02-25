# Ports collection makefile for:   kadu
# Date created:        17 July 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$
#

PORTNAME=		kadu
PORTVERSION=		0.5.0
PORTEPOCH=		1
CATEGORIES=		polish net-im
MASTER_SITES=		http://www.kadu.net/download/stable/:kadu \
			http://www.kadu.net/download/additions/:additions \
			http://www.kadu.net/download/modules_mirror/:modules \
			http://scripts.one.pl/spellchecker/stable/${PORTVERSION}/:aspell
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:kadu
DIST_SUBDIR=		kadu
EXTRACT_ONLY=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		mwisnicki+freebsd@gmail.com
COMMENT=		QT Gadu-Gadu client

LIB_DEPENDS=		gadu.3:${PORTSDIR}/polish/libgadu\
			sndfile.1:${PORTSDIR}/audio/libsndfile

TABS_MOD_DISTFILE=	tabs-20061223.tar.bz2
ASPELL_MOD_DISTFILE=	spellchecker-0.20.tar.gz

GG6_EMOTS_DISTFILE=	kompatybilne_z_GG6.tar.gz
GG7_EMOTS_DISTFILE=	dodatkowe_emoty_GG7.tar.gz

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_OPENSSL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-existing-libgadu="${LOCALBASE}" \
			--with-includes="${LOCALBASE}/include ${X11BASE}/include" \
			--with-libs="${LOCALBASE}/lib ${X11BASE}/lib" \
			--program-transform-name=''
CONFIGURE_ENV=		QTDIR="${QT_PREFIX}"

USE_QT_VER=		3
QT_NONSTANDARD=		yes
WANT_GNOME=		yes
INSTALLS_ICONS=		yes

WRKSRC=			${WRKDIR}/${PORTNAME}

OPTIONS=	ASPELL	"Build spell checking module"	off \
		ARTS	"Build aRts sound module"	off \
		ESOUND	"Build Esound module"		off \
		GG_EMOTS	"Install GG-compatible emoticons"	off \
		PHEADERS	"Use precompiled headers to speed up build"	on \
		TABS	"Build tabs module"		off

.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	pspell.16:${PORTSDIR}/textproc/aspell
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

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND_MOD=""
KADU_SHARED_MODULES+=	esd_sound
.else
PLIST_SUB+=	ESOUND_MOD="@comment "
.endif

.if defined(WITH_GG_EMOTS)
PLIST_SUB+=	GG_EMOTS=""
DISTFILES+=	${GG6_EMOTS_DISTFILE}:additions \
		${GG7_EMOTS_DISTFILE}:additions
.else
PLIST_SUB+=	GG_EMOTS="@comment "
.endif

.if !defined(WITHOUT_PHEADERS)
CONFIGURE_ARGS+=	--enable-pheaders
USE_GCC=		3.4+
.endif

.if defined(WITH_TABS)
PLIST_SUB+=	TABS_MOD=""
DISTFILES+=	${TABS_MOD_DISTFILE}:modules
KADU_SHARED_MODULES+=	tabs
.else
PLIST_SUB+=	TABS_MOD="@comment "
.endif

post-patch:
	@${ECHO} "#!/usr/bin/true" > ${WRKSRC}/varia/scripts/autodownload

.for module in ${KADU_SHARED_MODULES}
	@${REINPLACE_CMD} -e 's|module_${module}=n|module_${module}=m|g' ${WRKSRC}/.config
.endfor

.for module in ${KADU_STATIC_MODULES}
	@${REINPLACE_CMD} -e 's|module_${module}=n|module_${module}=y|g' ${WRKSRC}/.config
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

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/kadu/kadu.desktop ${PREFIX}/share/applications

.include <bsd.port.post.mk>
