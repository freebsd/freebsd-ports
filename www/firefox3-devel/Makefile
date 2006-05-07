# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/www/firefox-devel/Makefile,v 1.26 2006/03/29 18:31:20 ahze Exp $
#

PORTNAME=	firefox
DISTVERSION=	2.0a1
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/bonecho/alpha1/source
#DISTNAME=	${PORTNAME}-${DISTVERSION}-source
DISTNAME=	bonecho-alpha1-source

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

LATEST_LINK=	firefox2
MOZILLA=	${PORTNAME}${MOZILLA_SUFX}
MOZILLA_SUFX=	-devel
MOZ_OPTIONS=	--program-transform-name='s/firefox/${MOZILLA}/'

USE_X_PREFIX=	yes
WANT_GNOME=	yes
ALL_TARGET=	default
CONFIGURE_ENV=	LOCALBASE=${LOCALBASE}
HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	3.4+

GECKO_PLIST_PRE_FILES=	lib/${MOZILLA}/chrome/icons/default/default.xpm
GECKO_PLIST_PRE_DIRS=	lib/${MOZILLA}/chrome/icons/default lib/${MOZILLA}/chrome/icons

FIREFOX_ICON=		${MOZILLA}.xpm
FIREFOX_ICON_SRC=	${PREFIX}/lib/${MOZILLA}/icons/default.xpm
MOZ_OPTIONS=	--enable-application=browser \
		--enable-system-cairo	\
		--enable-official-branding \
		--enable-canvas	\
		--with-system-nss

SYSTEM_PREFS=		${FAKEDIR}/lib/${MOZILLA}/defaults/pref/firefox.js
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

OPTIONS=	NEWTAB "Open external links in a new tab" on \
		SMB "Enable smb:// URI support using gnomevfs" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	does not build
.endif

.if ${OSVERSION} >= 600000
MOZ_OPTIONS+=	--enable-svg --enable-svg-renderer=cairo
.endif

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

post-extract::
	@${SED} -e 's|@FIREFOX_ICON@|${FIREFOX_ICON}|' \
		<${FILESDIR}/firefox.desktop.in >${WRKDIR}/${MOZILLA}.desktop

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/security/manager/ssl/src/Makefile.in
.for ii in modules/libpref/src/init extensions/sroaming/resources/content/prefs \
	embedding/minimo
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/ ; \
		/dom.disable_window_open_feature.toolbar/s/false/true/' \
		${WRKSRC}/${ii}/all.js
.endfor

pre-install:
	${ECHO_CMD} 'share/applications/${MOZILLA}.desktop' >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${FIREFOX_ICON}' >> ${PLIST}
.if !defined(WITHOUT_NEWTAB)
	${ECHO_CMD} >> ${SYSTEM_PREFS}
	${ECHO_CMD} "// Open external links in new tab" >> ${SYSTEM_PREFS}
	${ECHO_CMD} "pref(\"browser.link.open_external\", 3);" \
		>> ${SYSTEM_PREFS}
.endif # !defined(WITHOUT_NEWTAB)

do-install:
	if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
				${LN} -sf $${jpi} \
					${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ; \
				break; \
			fi; \
		done; \
	fi

post-install:
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${MKDIR} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default.xpm
	${LN} -sf ${FIREFOX_ICON_SRC} ${PREFIX}/share/pixmaps/${FIREFOX_ICON}

.include "${.CURDIR}/../mozilla/Makefile.common"
test:
	@${REINPLACE_CMD} -e 's|${MOZILLA}-bin|${MOZILLA:S/${MOZILLA_SUFX}//}|; \
		s|progbase=`basename "$progname"`|${MOZILLA:S/${MOZILLA_SUFX}//}|' \
		${FAKEDIR}/bin/${MOZILLA} \
		${FAKEDIR}/bin/${MOZILLA}-config
.include <bsd.port.post.mk>
