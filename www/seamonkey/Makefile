# New ports collection makefile for:	mozilla
# Date created:		31 Mar 1998
# Whom:			eivind/dima/jseger
#
# $FreeBSD$
#

PORTNAME=	seamonkey
DISTVERSION=	2.11
CATEGORIES?=	www ipv6
MASTER_SITES=	${MASTER_SITE_MOZILLA_EXTENDED}
MASTER_SITE_SUBDIR=	seamonkey/releases/${DISTVERSION}/source
DISTNAME=	seamonkey-${DISTVERSION}.source

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

BUILD_DEPENDS=	nspr>=4.9:${PORTSDIR}/devel/nspr \
		nss>=3.13.2:${PORTSDIR}/security/nss \
		sqlite3>=3.7.11:${PORTSDIR}/databases/sqlite3 \
		unzip:${PORTSDIR}/archivers/unzip

USE_AUTOTOOLS=	autoconf213:env
CONFLICTS_BUILD=	spidermonkey-1.[0-7]*
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GECKO=	gecko
WANT_GNOME=	yes
USE_QT4=	# empty
QT_NONSTANDARD=	yes
WANT_PERL=	yes
GNU_CONFIGURE=	yes
OBJDIR_BUILD=	yes
ALL_TARGET=	default
USE_GL=		gl
MAKE_JOBS_SAFE=	yes
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--program-transform-name='s/seamonkey/${MOZILLA}/' \
		--enable-application=suite

USE_MOZILLA=	# empty
MOZILLA_PLIST_DIRS=	bin lib
MOZ_PKGCONFIG_FILES=

NOT_FOR_ARCHS=	ia64

OPTIONS_DEFINE=	CHATZILLA COMPOSER GSTREAMER LDAP LIGHTNING MAILNEWS
OPTIONS_DEFAULT=CHATZILLA COMPOSER LDAP MAILNEWS

CHATZILLA_DESC?=Chatzilla IRC module
COMPOSER_DESC?=	HTML Composer module
LDAP_DESC?=	LDAP support for Mailnews
MAILNEWS_DESC?=	Mail and News modules

.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/comm-release
MOZSRC:=	${WRKSRC}/mozilla

.if ${ARCH} == amd64
CONFIGURE_TARGET=x86_64-portbld-freebsd${OSREL}
.elif ${ARCH} == powerpc64
.if ${OSVERSION} < 900033
BROKEN=		Needs binutils 2.17.50 to build
.else
MOZ_EXPORT+=	UNAME_m="powerpc64"
CFLAGS+=	-mminimal-toc
.endif
.endif

.if ! ${PORT_OPTIONS:MMAILNEWS}
EXTRA_PATCHES+=	${FILESDIR}/extra-mailnews-patch-bridge-bridge.mk \
		${FILESDIR}/extra-patch-configure.in
MOZ_OPTIONS+=	--disable-ldap --disable-mailnews
.else
# mail and news desired, but not LDAP
.if ! ${PORT_OPTIONS:MLDAP}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-bridge-bridge.mk
MOZ_OPTIONS+=	--disable-ldap --enable-mailnews
.else
MOZ_OPTIONS+=	--enable-ldap --enable-mailnews
.endif
.endif
.if ${PORT_OPTIONS:MCHATZILLA}
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif

.if ! ${PORT_OPTIONS:MCOMPOSER}
MOZ_OPTIONS+=	--disable-composer
.endif

.if ${ARCH} == amd64 || ${ARCH} == i386
BUILD_DEPENDS+=	yasm:${PORTSDIR}/devel/yasm
.endif

.if !empty(CXX:M*clang++*)
CFLAGS+=	-Wno-return-type-c-linkage
.endif

.if ${PORT_OPTIONS:MLIGHTNING}
MOZ_OPTIONS+=	--enable-calendar
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=calendar
LIGHTNING_DIR=	share/lightning
XPI_FILE=	${MOZ_OBJDIR}/mozilla/dist/xpi-stage/lightning.xpi
XPI_LIBDIR=	${PREFIX}/lib/xpi
XPI_ORIG_ID=	{e2fda1a4-762b-4020-b5ad-a41df1933103}
XPI_ID=		lightning@seamonkey.mozilla.org
.else
MOZ_OPTIONS+=	--disable-calendar
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/suite/app/nsSuiteApp.cpp
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/mozilla/modules/libpref/src/init/all.js
	@${REINPLACE_CMD} -e 's|libgnome-2.so.0|libgnome-2.so|' \
		${WRKSRC}/mozilla/toolkit/xre/nsNativeAppSupportUnix.cpp \
		${WRKSRC}/mozilla/image/decoders/icon/gtk/nsIconChannel.cpp
	@${REINPLACE_CMD} -e 's|libgnomeui-2.so.0|libgnomeui-2.so|' \
		${WRKSRC}/mozilla/toolkit/xre/nsNativeAppSupportUnix.cpp \
		${WRKSRC}/mozilla/image/decoders/icon/gtk/nsIconChannel.cpp
	@${REINPLACE_CMD} -e 's|libgnomevfs-2.so.0|libgnomevfs-2.so|' \
		${WRKSRC}/mozilla/image/decoders/icon/gtk/nsIconChannel.cpp
	@${SED} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/${MOZILLA}.desktop
pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

pre-install:
	${ECHO_CMD} share/applications/${MOZILLA}.desktop >> ${PLIST}
	${ECHO_CMD} "@unexec ${RMDIR} %D/share/applications 2>/dev/null || ${TRUE}" >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${MOZILLA}.png' >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${LN} -sf ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png \
		${PREFIX}/share/pixmaps/${MOZILLA}.png

post-install:
.if ${PORT_OPTIONS:MLIGHTNING}
	@${MKDIR} ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/seamonkey
	@(cd ${XPI_LIBDIR}/${XPI_ID}; ${TAR} -xf ${XPI_FILE})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${XPI_ID}
	@${REINPLACE_CMD} -i "" "s/${XPI_ORIG_ID}/${XPI_ID}/" ${XPI_LIBDIR}/${XPI_ID}/install.rdf
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${XPI_ID}
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${LOCALBASE}/lib/seamonkey/extensions 2>/dev/null || true
	@${LN} -sf ${XPI_LIBDIR}/${XPI_ID} ${XPI_LIBDIR}/symlinks/seamonkey 2>/dev/null || true
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} 'lib/xpi/symlinks/seamonkey/${XPI_ID}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${XPI_ID} ${LOCALBASE}/lib/seamonkey/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/seamonkey/extensions/${XPI_ID}' >> ${TMPPLIST}
	@(cd ${XPI_LIBDIR}; ${FIND} ${XPI_ID} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks/seamonkey 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi 2>/dev/null || true' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
