# New ports collection makefile for:	phoenix
# Date created:			2002/10/21
# Whom:				Alan Eldridge <alane@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	firefox
PORTVERSION=	0.8
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_MOZILLA}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTVERSION}
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Web browser based on the browser portion of Mozilla

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2 \
		nspr4.1:${PORTSDIR}/devel/nspr
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2

ALL_TARGET=	default
CONFIGURE_ENV=	WITH_GTK2=yes \
		LOCALBASE=${LOCALBASE}
FAKEDIR=	${WRKDIR}/fake
FAKESUBDIR=	${FAKEDIR}/lib/${PORTNAME}
HAS_CONFIGURE=	yes
ESD_LIB=	libesd.so.2
LOCAL_PREFIX=	${PREFIX}/lib/${PORTNAME}
NO_MTREE=	yes
PLIST=		${WRKDIR}/plist
PLUGINSDIR=	${PREFIX}/lib/browser_plugins
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 libidl
USE_ICONV=	yes
USE_PERL5_BUILD=yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/mozilla

JPI_LIST?=\
	${LOCALBASE}/jdk1.4.2/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.4.1/jre/plugin/${ARCH}/ns610/libjavaplugin_oji.so \
	${LOCALBASE}/diablo-jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so \
	${LOCALBASE}/jdk1.3.1/jre/plugin/${ARCH}/ns600/libjavaplugin_oji.so

OPTIONS=	DEBUG "Build a debugging image" off \
		HEADERS "Install headers and IDL files" off \
		LOGGING "Enable additional log messages" off \
		OPTIMIZED_CFLAGS "Enable some additional optimizations" off \
		XFT "Enable support for anti-aliased fonts" on

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
WITH_LOGGING=		yes
CONFIGURE_ENV+=		WITH_DEBUG=yes
.endif # defined(WITH_DEBUG)

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=		-O2
.endif # defined(WITH_OPTIMIZED_CFLAGS)

.if defined(WITH_LOGGING)
CONFIGURE_ENV+=	WITH_LOGGING=yes
.endif # defined(WITH_LOGGING)

.if defined(WITHOUT_XFT)
CONFIGURE_ENV+=	WITHOUT_XFT=yes
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
.endif # !defined(WITHOUT_XFT)

CPPFLAGS+=		-I${X11BASE}/include -I${LOCALBASE}/include
CFLAGS+=		${PTHREAD_CFLAGS}
LDFLAGS+=		-L${X11BASE}/lib
LIBS+=			${PTHREAD_LIBS}

EXTRA_SCRIPTS=		${PORTNAME}.rb

.if ${ARCH} == "alpha" && ${OSVERSION} < 500035
IGNORE=	"core dumps on alpha during post-build"
.endif

pre-extract::
	@${ECHO_MSG}
	@${ECHO_MSG} "Extracting source (this takes a while) ..."
	@${ECHO_MSG}

post-extract::
# FAKEDIR is here so that nsinstall will install under FAKEDIR, not
# under PREFIX.  See pre-install and do-install for details.
	@${SED} -e 's|@CPPFLAGS@|${CPPFLAGS}|'		\
		-e 's|@CFLAGS@|${CFLAGS}|'		\
		-e 's|@LDFLAGS@|${LDFLAGS}|'		\
		-e 's|@LIBS@|${LIBS}|'			\
		-e 's|@X11BASE@|${X11BASE}|'		\
		-e 's|@LOCALBASE@|${LOCALBASE}|'	\
		-e 's|@PREFIX@|${FAKEDIR}/lib/firefox|'	\
		-e 's|@PERL@|${PERL5}|'			\
		<${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig

post-patch:
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/build/unix/run-mozilla.sh
	@${PERL} -pi -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/nsprpub/configure
	@${PERL} -pi -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/nsprpub/config/config.mk \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/directory/c-sdk/config/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in
	@${PERL} -pi -e 's|libesd\.so\.0|${ESD_LIB}|g' \
		${WRKSRC}/widget/src/gtk2/nsSound.cpp
.for ii in modules/libpref/src/init browser/app/profile \
	calendar/sunbird/app/profile
	${MV} ${WRKSRC}/${ii}/all.js ${WRKSRC}/${ii}/all.js.bak
	${SED} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
	< ${WRKSRC}/${ii}/all.js.bak > ${WRKSRC}/${ii}/all.js
.endfor

pre-configure:
	@if [ -n "`${PKG_INFO} -xI '^bind[0-9]*-base-[0-9]'`" ]; then \
		${ECHO_CMD} "${PKGNAME}: bind installed with PORT_REPLACES_BASE_BIND causes build problems."; \
		${FALSE}; \
	fi

pre-install:
# Overview:  the program installs itself in FAKEDIR, then a list is made of the
# files and directories in there.  This is the PLIST (packing list) for the
# package, replacing the traditional pkg-plist file.
	@${RM} -rf ${FAKEDIR} ${PLIST}
	@${MKDIR} ${FAKEDIR}/lib/browser_plugins
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		Makefile ${MAKE_ARGS} install
.for ii in mac win
.for jj in / .jar
	@${RM} -rf ${FAKEDIR}/lib/mozilla-1.6/chrome/en-${ii}${jj}
.endfor
.endfor

.if !defined (WITH_HEADERS)
	@${RM} -fr ${FAKEDIR}/share/idl ${FAKEDIR}/include
.endif
.for ii in firefox Firefox firefox-config ${EXTRA_SCRIPTS}
	@${ECHO_CMD} bin/${ii} >> ${PLIST}
.endfor
	@cd ${FAKEDIR} && ${FIND} * ! -type d | ${SORT} >> ${PLIST}; \
	${FIND} * -type d -empty | ${SORT} | ${SED} -e \
		"s:^:@exec ${MKDIR} %D/:" -e "s:$$: || true:" >> ${PLIST}; \
	${FIND} * -type d -empty | ${SORT} -r | ${SED} -e \
		"s:^:@unexec ${RMDIR} %D/:" -e "s:$$: || true:" >> ${PLIST}; \
	${FIND} * -type d ! -empty | ${SORT} -r | ${SED} -e "s:^:@dirrm :" | \
		${GREP} / >> ${PLIST}

do-install:
# This is the actual installation.  First, the contents of FAKEDIR are
# just copied to PREFIX.
	cd ${FAKEDIR} && ${FIND} * | ${CPIO} -dmp --quiet ${PREFIX}

post-install:
.for i in ${EXTRA_SCRIPTS}
	${INSTALL_SCRIPT} ${FILESDIR}/${i} ${PREFIX}/bin
.endfor
.for ii in f F
	${RM} -f ${PREFIX}/bin/${ii}irefox
	${LN} -sf ${LOCAL_PREFIX}/bin/firefox ${PREFIX}/bin/${ii}irefox
.endfor
	${PERL} -pi -e 's|${FAKEDIR}|${PREFIX}|g' ${LOCAL_PREFIX}/bin/firefox
	${RM} -f ${PREFIX}/bin/firefox-config
	${LN} -sf ${LOCAL_PREFIX}/bin/mozilla-config \
		${PREFIX}/bin/firefox-config
	${PERL} -pi -e 's|${FAKEDIR}|${PREFIX}|g' ${LOCAL_PREFIX}/bin/mozilla-config
	${FIND} ${LOCAL_PREFIX}/lib/pkgconfig -type f | ${XARGS} ${PERL} -pi -e \
		's|${FAKEDIR}|${PREFIX}|g'
	-if [ ! -L ${PREFIX}/lib/browser_plugins/libjavaplugin_oji.so ]; then \
		for jpi in ${JPI_LIST}; do \
			if [ -f $${jpi} ]; then \
				${LN} -sf $${jpi} \
					${PLUGINSDIR}/libjavaplugin_oji.so ; \
				break; \
			fi; \
		done; \
	fi

.include <bsd.port.post.mk>
