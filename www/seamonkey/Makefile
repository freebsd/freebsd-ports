# Created by: eivind/dima/jseger
# $FreeBSD$

PORTNAME=	seamonkey
DISTVERSION=	2.25
CATEGORIES?=	www mail news editors irc ipv6
MASTER_SITES=	MOZILLA/${PORTNAME}/releases/${DISTVERSION}/source \
		https://ftp.mozilla.org/pub/mozilla.org/${PORTNAME}/candidates/${DISTVERSION}-candidates/build1/source/
DISTFILES=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}.source${EXTRACT_SUFX}

MAINTAINER=	gecko@FreeBSD.org
COMMENT=	The open source, standards compliant web browser

BUILD_DEPENDS=	nspr>=4.10.3:${PORTSDIR}/devel/nspr \
		nss>=3.15.4:${PORTSDIR}/security/nss \
		harfbuzz>=0.9.25:${PORTSDIR}/print/harfbuzz \
		libvorbis>=1.3.4:${PORTSDIR}/audio/libvorbis \
		opus>=1.1:${PORTSDIR}/audio/opus \
		libvpx>=1.3.0:${PORTSDIR}/multimedia/libvpx \
		sqlite3>=3.8.1:${PORTSDIR}/databases/sqlite3 \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:${PORTSDIR}/databases/py-sqlite3 \
		v4l_compat>0:${PORTSDIR}/multimedia/v4l_compat \
		zip:${PORTSDIR}/archivers/zip \
		unzip:${PORTSDIR}/archivers/unzip
#		cairo>=1.12.16,2:${PORTSDIR}/graphics/cairo \

LIB_DEPENDS=	libv4l2.so:${PORTSDIR}/multimedia/libv4l

EM_VERSION=	1.6.1_pre20140112
L_VERSION=	3.0b1

SSP_UNSAFE=	yes
USE_AUTOTOOLS=	autoconf213:env
USE_PYTHON_BUILD=2
OBJDIR_BUILD=	# in-tree build broken after bug 789837
USE_BZIP2=	yes
USE_GECKO=	gecko
WANT_GNOME=	yes
USE_QT4=	# empty
QT_NONSTANDARD=	yes
WANT_PERL=	yes
ALL_TARGET=	default
USE_GL=		gl
USES=		dos2unix
DOS2UNIX_FILES=	mozilla/media/webrtc/trunk/webrtc/system_wrappers/source/spreadsortlib/spreadsort.hpp
MOZ_PIS_SCRIPTS=	moz_pis_S50cleanhome

MOZ_EXTENSIONS=	default
MOZ_OPTIONS+=	--program-transform-name='s/seamonkey/${MOZILLA}/' \
		--enable-application=suite

USE_MOZILLA=	-cairo
MOZ_PKGCONFIG_FILES=

NOT_FOR_ARCHS=	ia64

OPTIONS_DEFINE=	CHATZILLA COMPOSER ENIGMAIL LDAP LIGHTNING MAILNEWS
OPTIONS_DEFAULT=CHATZILLA COMPOSER ENIGMAIL LDAP LIGHTNING MAILNEWS

CHATZILLA_DESC?=Chatzilla IRC module
COMPOSER_DESC?=	HTML Composer module
LDAP_DESC?=	LDAP support for Mailnews
MAILNEWS_DESC?=	Mail and News modules

# non-client.mk objdir build broken after bug 846540
.undef GNU_CONFIGURE
ALL_TARGET=	build
MAKEFILE=	${WRKSRC}/client.mk

NO_STAGE=	yes
.include "${.CURDIR}/../../www/firefox/Makefile.options"
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHATZILLA}
MOZ_EXTENSIONS:=	${MOZ_EXTENSIONS},irc
.endif

.include <bsd.port.pre.mk>

WRKSRC=		${WRKDIR}/comm-release
MOZSRC:=	${WRKSRC}/mozilla

XPI_LIBDIR=	${PREFIX}/lib/xpi

# avoid clang 3.2/3.3 crash in js/src/jsgc.cpp on refillFreeList<(js::AllowGC)1>
# http://svnweb.freebsd.org/changeset/base/255804
.if ${CHOSEN_COMPILER_TYPE} == clang && ${ARCH} == i386 && ${OSVERSION} < 1000056
. if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
BROKEN=		Cannot build with OPTIMIZED_CFLAGS option due to \
		a ${CHOSEN_COMPILER_TYPE} bug: unset the option or \
		use FAVORITE_COMPILER=gcc in Makefile.local/make.conf
# apply workaround only for -O2 or greater
. elif ${CXXFLAGS:M-O*} && ! ${CXXFLAGS:M-O[01]}
.  if ${MACHINE_CPU:Msse2}
CXXFLAGS+=	-msse2
.  else
CXXFLAGS+=	-O1
.  endif
. endif
.endif

.if ${PORT_OPTIONS:MALSA}
BUILD_DEPENDS+=	alsa-lib>=1.0.27.2_1:${PORTSDIR}/audio/alsa-lib
.endif

.if ! ${PORT_OPTIONS:MMAILNEWS}
MOZ_OPTIONS+=	--disable-ldap --disable-mailnews
.else
# mail and news desired, but not LDAP
.if ! ${PORT_OPTIONS:MLDAP}
MOZ_OPTIONS+=	--disable-ldap --enable-mailnews
.else
MOZ_OPTIONS+=	--enable-ldap --enable-mailnews
.endif
.if ${PORT_OPTIONS:MENIGMAIL}
#MASTER_SITES+=	https://www.enigmail.net/download/source/:enigmail
MASTER_SITES+=	https://dev.gentoo.org/~polynomial-c/mozilla/:enigmail
DISTFILES+=	${EM_DISTFILE}:enigmail
RUN_DEPENDS+=	gpg:${PORTSDIR}/security/gnupg
EM_DISTNAME=	enigmail-${EM_VERSION}
EM_DISTFILE=	${EM_DISTNAME}.tar.xz
EM_XPI_FILE=	${WRKSRC}/mailnews/extensions/enigmail/build/${EM_DISTNAME}-${OPSYS:L}-${ARCH:S/amd64/x86_64/:S/i386/x86/}-gcc3.xpi
EM_ORIG_ID=	{847b3a00-7ab1-11d4-8f02-006008948af5}
EM_ID=		${PORTNAME}@mozilla-enigmail.org
EM_ID_RFILES=	${XPI_LIBDIR}/${EM_ID}/install.rdf \
		${XPI_LIBDIR}/${EM_ID}/components/enigmail.js \
		${XPI_LIBDIR}/${EM_ID}/modules/enigmailCommon.jsm
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-mailnews-extensions-enigmail-config-getOsTarget.pl
.endif
.endif

.if ! ${PORT_OPTIONS:MCOMPOSER}
MOZ_OPTIONS+=	--disable-composer
.endif

.if ${PORT_OPTIONS:MLIGHTNING}
MOZ_OPTIONS+=	--enable-calendar
MOZ_MK_OPTIONS+=	MOZ_CO_PROJECT=calendar
LIGHTNING_DIR=	share/lightning
XPI_FILE=	${MOZ_OBJDIR}/mozilla/dist/xpi-stage/lightning-${L_VERSION}.en-US.${OPSYS:L}${OSREL}-${ARCH:S/x86/i386/:S/amd64/x86_64/}.xpi
XPI_ORIG_ID=	{e2fda1a4-762b-4020-b5ad-a41df1933103}
XPI_ID=		lightning@seamonkey.mozilla.org
.else
MOZ_OPTIONS+=	--disable-calendar
.endif

.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
post-extract:
	@${TAR} -xf ${_DISTDIR}/${EM_DISTFILE} \
		-C ${WRKSRC}/mailnews/extensions
.endif

post-patch:
	@${REINPLACE_CMD} -e '/MOZPNG/s/=[0-9]*/=10511/' \
		${MOZSRC}/configure.in ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/suite/app/nsSuiteApp.cpp
	@${REINPLACE_CMD} -e '/accessibility.typeaheadfind.enablesound/s/true/false/' \
		${WRKSRC}/mozilla/modules/libpref/src/init/all.js
	@${SED} -e 's|%%MOZILLA%%|${MOZILLA}|g' \
		< ${FILESDIR}/seamonkey.desktop.in > \
		${WRKDIR}/${MOZILLA}.desktop
.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
	@${REINPLACE_CMD} -e 's,/usr/bin/perl,${PERL},' \
		${WRKSRC}/mailnews/extensions/enigmail/util/fixlang.pl \
		${WRKSRC}/mailnews/extensions/enigmail/util/make-lang-xpi.pl
	@${REINPLACE_CMD} -e '/^xpi/s/$$/ all/' \
		-e '/^XPI_MODULE_VERS/s/= .*/= ${EM_VERSION}/' \
		${WRKSRC}/mailnews/extensions/enigmail/Makefile
	@${REINPLACE_CMD} -e '/em:version/s,>[^<]*<,>${EM_VERSION}<,' \
		-e '/em:maxVersion/s/pre//' \
		${WRKSRC}/mailnews/extensions/enigmail/package/install.rdf
.endif

pre-configure:
	(cd ${WRKSRC} && ${AUTOCONF})
	(cd ${MOZSRC} && ${AUTOCONF})
	(cd ${MOZSRC}/js/src/ && ${AUTOCONF})

.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
post-configure:
	cd ${WRKSRC}/mailnews/extensions/enigmail/ && \
		${SETENV} ${MAKE_ENV} ./configure
.endif

.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
post-build:
	${SETENV} ${MAKE_ENV} ${GMAKE} -j${MAKE_JOBS_NUMBER} all xpi \
		-C ${WRKSRC}/mailnews/extensions/enigmail
.endif

port-pre-install:
	${ECHO_CMD} share/applications/${MOZILLA}.desktop >> ${PLIST}
	${ECHO_CMD} 'share/pixmaps/${MOZILLA}.png' >> ${PLIST}

post-install:
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop ${PREFIX}/share/applications/
	${LN} -sf ${PREFIX}/lib/${MOZILLA}/chrome/icons/default/default48.png \
		${PREFIX}/share/pixmaps/${MOZILLA}.png
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
.endif
.if ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
	@${MKDIR} ${XPI_LIBDIR}/${EM_ID} ${XPI_LIBDIR}/symlinks/${PORTNAME}
	@(cd ${XPI_LIBDIR}/${EM_ID}; ${TAR} -xf ${EM_XPI_FILE})
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${XPI_LIBDIR}/${EM_ID}
	@${REINPLACE_CMD} -i "" "s/${EM_ORIG_ID}/${EM_ID}/" ${EM_ID_RFILES}
	@${CHMOD} -R a+rX,go-w ${XPI_LIBDIR}/${EM_ID}
	@${LN} -sf ${XPI_LIBDIR}/${EM_ID} ${LOCALBASE}/lib/${PORTNAME}/extensions 2>/dev/null || true
	@${LN} -sf ${XPI_LIBDIR}/${EM_ID} ${XPI_LIBDIR}/symlinks/${PORTNAME} 2>/dev/null || true
	@(cd ${XPI_LIBDIR}; ${FIND} ${EM_ID} -not -type d) | ${SORT} | \
		${SED} -ne 's,^,lib/xpi/,p' >> ${TMPPLIST}
	@${ECHO_CMD} 'lib/xpi/symlinks/${PORTNAME}/${EM_ID}' >> ${TMPPLIST}
	@${ECHO_CMD} '@exec ${LN} -sf %D/lib/xpi/${EM_ID} ${LOCALBASE}/lib/${PORTNAME}/extensions 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec ${RM} -f ${LOCALBASE}/lib/${PORTNAME}/extensions/${EM_ID}' >> ${TMPPLIST}
	@(cd ${XPI_LIBDIR}; ${FIND} ${EM_ID} -type d) | ${SORT} -r | \
		${SED} -ne 's,^,@dirrm lib/xpi/,p' >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MLIGHTNING} || ${PORT_OPTIONS:MMAILNEWS} && ${PORT_OPTIONS:MENIGMAIL}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks/${PORTNAME} 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi/symlinks 2>/dev/null || true' >> ${TMPPLIST}
	@${ECHO_CMD} '@unexec rmdir %D/lib/xpi 2>/dev/null || true' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>
