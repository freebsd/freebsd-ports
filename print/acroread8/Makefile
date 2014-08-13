# Created by: hrs
# $FreeBSD: head/print/acroread8/Makefile 364018 2014-08-04 15:10:41Z mandree $

PORTNAME=	acroread8
PORTVERSION=	8.1.7
PORTREVISION=	5
CATEGORIES?=	print linux
MASTER_SITES?=	http://ardownload.adobe.com/pub/adobe/reader/unix/8.x/${PORTVERSION}/${ADOBE_LANG:tl}/ \
		ftp://ftp.adobe.com/pub/adobe/reader/unix/8.x/${PORTVERSION}/${ADOBE_LANG:L}/
DISTNAME=	AdobeReader_${ADOBE_LANG:tl}-${PORTVERSION}-1.i486
DIST_SUBDIR=	acroread

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Adobe Reader for view, print, and search PDF documents (${ADOBE_LANG})

LICENSE=	Adobe_WWEULA_20080204_1313
LICENSE_NAME=	Adobe EULA (Reader_Player_AIR_WWEULA-en_US-20080204_1313)
LICENSE_TEXT=	${INSTALLDIR}/Adobe/Reader8/Reader/Legal/en_US/License.txt
LICENSE_PERMS=	auto-accept

RUN_DEPENDS=	acroreadwrapper>=0.0.20100806:${PORTSDIR}/print/acroreadwrapper

FORBIDDEN=	No longer maintained upstream since 2011-11-03
DEPRECATED=	No longer maintained upstream since 2011-11-03
EXPIRATION_DATE=2014-08-31

RESTRICTED=	Must fill out redistribution form at http://www.adobe.com/products/acrobat/distribute.html
ONLY_FOR_ARCHS=	amd64 i386
USES=		tar:bzip2
USE_LINUX=	yes
USE_LINUX_APPS=	cups-libs gtk2 pango libgcrypt libgpg-error
USE_LDCONFIG=	yes
#USE_GNOME=	desktopfileutils
NO_BUILD=	yes
PLIST_SUB=	ACRODIR=${ACRODIR} \
		ACROBASE=${ACROBASE} \
		ADOBEBASE=${ADOBEBASE} \
		PLUGINDIR=${PLUGINDIR} \
		ADOBE_LANG=${ADOBE_LANG:tu} \
		LOCALE_NAME=${LOCALE_NAME}
SUB_FILES=	ln mv rm pkg-deinstall
SUB_LIST=	ADOBE_LANG=${ADOBE_LANG:tu} \
		ACROBASE=${ACROBASE}
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
WRKSRC=		${WRKDIR}/AdobeReader

LANGCODE=	chs:zh_CN cht:zh_TW dan:da_DK deu:de_DE enu:en_US \
		esp:es_ES fra:fr_FR ita:it_IT jpn:ja_JP kor:ko_KR \
		nld:nl_NL nor:nb_NO ptb:pt_BR suo:fi_FI sve:sv_SE

ADOBE_LANG?=	ENU
.if ${ADOBE_LANG:tu} != ENU
SUB_FILES+=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
.endif
.for L in ${ADOBE_LANG:tl}
LOCALE_NAME=	${LANGCODE:M${L}\:*:C/.*\://}
LANG_${L:tu}=	""
LANG_NON${L:tu}="@comment "
.endfor
.for L in ${LANGCODE:C/\:.*//:tu}
LANG_${L}?=	"@comment "
LANG_NON${L}?=	""
PLIST_SUB+=	LANG_${L}=${LANG_${L}}
PLIST_SUB+=	LANG_NON${L}=${LANG_NON${L}}
.endfor

ADOBEBASE=	Adobe
ACROBASE=	${ADOBEBASE}/Reader8
ACRODIR=	${ACROBASE}/${ADOBE_LANG:tu}
PLUGINDIR=	lib/browser_linux_plugins
INSTALLDIR=	${PREFIX}/${ACRODIR}
INSTALLEXEC=	${SETENV} UNAME_s=Linux \
		    InstallDir=${INSTALLDIR} \
		    UNAME_r="Linux Compatibility on FreeBSD" \
		    ${SH} ./INSTALL \
		    --install_path=${STAGEDIR}${INSTALLDIR} > /dev/null

pre-install:
	@${MKDIR} ${WRKDIR}/bin
	@${INSTALL_SCRIPT} \
	    ${WRKDIR}/ln ${WRKDIR}/rm ${WRKDIR}/mv \
	    ${WRKDIR}/bin
do-install:
	@${ECHO_CMD} Installing...
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/desktop-directories
	@${MKDIR} ${STAGEDIR}${INSTALLDIR}
	@cd ${WRKSRC} && ${SETENV} PATH=${WRKDIR}/bin:${PATH} \
	    ${INSTALLEXEC} > /dev/null

post-install:
	${RM} ${STAGEDIR}${PREFIX}/Adobe/Reader8/${ADOBE_LANG:tu}/Adobe/Reader8/Reader/GlobalPrefs/.config

.include <bsd.port.mk>
