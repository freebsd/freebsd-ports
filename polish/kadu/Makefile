# Ports collection makefile for:   kadu
# Date created:        17 July 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$
#

PORTNAME=		kadu
PORTVERSION=		0.4.3
PORTREVISION=		2
PORTEPOCH=		1
CATEGORIES=		polish net-im
MASTER_SITES=		http://www.kadu.net/download/stable/:kadu \
			http://michal.gov.one.pl/tabs/:tabs \
			http://scripts.one.pl/spellchecker/stable/${PORTVERSION}/:aspell
DISTFILES=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:kadu
EXTRACT_ONLY=		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=		mwisnicki+freebsd@gmail.com
COMMENT=		QT Gadu-Gadu client

LIB_DEPENDS=		gadu.3:${PORTSDIR}/polish/libgadu\
			sndfile.1:${PORTSDIR}/audio/libsndfile

TABS_MOD_DISTFILE=	tabs-kadu-0.4.0.tar.gz
ASPELL_MOD_DISTFILE=	spellchecker-0.15.tar.gz

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
		TABS	"Build tabs module"		off

.include <bsd.port.pre.mk>

.if defined(WITH_ASPELL)
LIB_DEPENDS+=	pspell.16:${PORTSDIR}/textproc/aspell
PLIST_SUB+=	ASPELL_MOD=""
DISTFILES+=	${ASPELL_MOD_DISTFILE}:aspell
.else
PLIST_SUB+=	ASPELL_MOD="@comment "
.endif

.if defined(WITH_ARTS)
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
PLIST_SUB+=	ARTS_MOD=""
.else
PLIST_SUB+=	ARTS_MOD="@comment "
.endif

.if defined(WITH_ESOUND)
USE_GNOME+=	esound
PLIST_SUB+=	ESOUND_MOD=""
.else
PLIST_SUB+=	ESOUND_MOD="@comment "
.endif

.if defined(WITH_TABS)
PLIST_SUB+=	TABS_MOD=""
DISTFILES+=	${TABS_MOD_DISTFILE}:tabs
.else
PLIST_SUB+=	TABS_MOD="@comment "
.endif

post-patch:
.if ${OSVERSION} < 500000
	@${ECHO} "MODULE_LDFLAGS=\"-lcrypto\"" >> ${WRKSRC}/modules/encryption/spec
.endif

.if defined(WITH_ASPELL)
	@${REINPLACE_CMD} -e 's|module_spellchecker=n|module_spellchecker=y|g' ${WRKSRC}/.config
	@cd ${WRKSRC}/modules && ${TAR} -zxf ${DISTDIR}/${ASPELL_MOD_DISTFILE}
.endif

.if defined(WITH_ARTS)
	@${REINPLACE_CMD} -e 's|module_arts_sound=n|module_arts_sound=y|g' ${WRKSRC}/.config
.endif

.if defined(WITH_ESOUND)
	@${REINPLACE_CMD} -e 's|module_esd_sound=n|module_esd_sound=y|g' ${WRKSRC}/.config
.endif

.if defined(WITH_TABS)
	@${REINPLACE_CMD} -e 's|module_tabs=n|module_tabs=y|g' ${WRKSRC}/.config
	@cd ${WRKSRC}/modules && ${TAR} -zxf ${DISTDIR}/${TABS_MOD_DISTFILE}
.endif

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/kadu/kadu.desktop ${PREFIX}/share/applications

.include <bsd.port.post.mk>
