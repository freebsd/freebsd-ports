# New ports collection makefile for:	beonex
# Date created:				2002-09-26
# Whom:					trevor
# based on ports/www/mozilla
#
# $FreeBSD$
#

PORTNAME=	beonex
PORTVERSION=	0.8.1
CATEGORIES=	www
MASTER_SITES=	http://ftp.ibiblio.org/pub/packages/infosystems/WWW/clients/beonex/communicator/0.8/ \
		ftp://ftp.ibiblio.org/pub/packages/infosystems/WWW/clients/beonex/communicator/0.8/
DISTNAME=	beonex-comm-${PORTVERSION}-stable-1-source-tarball

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		mng.1:${PORTSDIR}/graphics/libmng \
		freetype.9:${PORTSDIR}/print/freetype2

WRKSRC=		${WRKDIR}/mozilla

WITHOUT_CHATZILLA="see <URL:http://online.securityfocus.com/archive/1/270249>"

USE_BZIP2=		yes
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/* --exclude */macbuild/*\
				--exclude */package/*

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	orbit gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=					\
		--disable-auto-deps		\
		--enable-chrome-format=jar	\
		--disable-cpp-exceptions	\
		--disable-cpp-rtti		\
		--enable-crypto			\
		--disable-debug			\
		--enable-default-toolkit=gtk	\
		--enable-double-buffer		\
		--disable-dtd-debug		\
		--disable-jsd			\
		--enable-mathml			\
		--disable-md			\
		--disable-optimize		\
		--disable-pedantic		\
		--disable-plaintext-editor-only	\
		--enable-strip			\
		--enable-strip-libs		\
		--disable-tests			\
		--disable-xterm-updates		\
		--enable-xinerama		\
		--with-system-jpeg=${LOCALBASE}	\
		--with-system-mng=${LOCALBASE}	\
		--with-system-png=${LOCALBASE}
# disabled due to compilation errors
#		--with-pthreads
#		--enable-svg

# compiles but segfaults on 5.0-RC3/alpha
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/pkg-plist
# LDAP is only used by mail and news so disable both together
.if defined(WITHOUT_MAILNEWS)
CONFIGURE_ARGS+=	--disable-ldap --disable-mailnews
.else
# mail and news desired, but not LDAP
.if defined(WITHOUT_LDAP)
CONFIGURE_ARGS+=	--disable-ldap --enable-mailnews
.else
CONFIGURE_ARGS+=	--enable-ldap --enable-mailnews
.endif
.endif

.if !defined(WITHOUT_CHATZILLA)
CONFIGURE_ARGS+=	--enable-extensions=cookie,wallet,content-packs,pref,transformiix,irc,spellcheck,xmlterm
.else
CONFIGURE_ARGS+=	--enable-extensions=cookie,wallet,content-packs,pref,transformiix,spellcheck,xmlterm
.endif
CONFIGURE_ENV=	BUILD_OFFICIAL=1 MOZILLA_OFFICIAL=1 MOZ_INTERNAL_LIBART_LGPL=1 \
		${CC}=${CXX}

.include <bsd.port.pre.mk>

MAKE_ENV=	LD_LIBRARY_PATH=${WRKSRC}/dist/bin \
		MOZ_INTERNAL_LIBART_LGPL=1
ALL_TARGET=	default

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-reorder
.endif

.if exists(${LOCALBASE}/include/freetype/freetype.h)
BROKEN="You must upgrade your freetype port to 1.3.1_2 or higher before installing Beonex.  If you have 1.3.1_2 installed, please remove ${LOCALBASE}/include/freetype, then build Beonex"
.endif

pre-everything::
	@ ${CAT} ${PKGMESSAGE}

post-build:
.if defined(WITHOUT_CHATZILLA)
	${RM} -f ${WRKSRC}/dist/bin/chrome/chatzilla.jar \
		${WRKSRC}/extensions/irc/js/lib/chatzilla-service.js
.endif
	(cd ${WRKSRC}/dist/bin && \
		${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regxpcom; \
		${ECHO_CMD} skin,install,select,modern/1.0 >> \
			chrome/installed-chrome.txt; \
		${ECHO_CMD} locale,install,select,en-US >> \
			chrome/installed-chrome.txt; \
		${SETENV} LD_LIBRARY_PATH=. MOZILLA_FIVE_HOME=. ./regchrome)

pre-install:
	${ECHO_CMD} bin/beonex > ${PLIST}
.for ii in component.reg components/xpti.dat
	${ECHO_CMD} '@unexec rm -f %D/lib/beonex/${ii} || true' >> ${PLIST}
.endfor
	cd ${WRKSRC}/dist/bin && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's:^:lib/beonex/:' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's:^:@dirrm lib/beonex/:' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/beonex >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/lib/beonex
	${CHMOD} 755 ${PREFIX}/lib/beonex
	cd ${WRKSRC}/dist/bin && ${FIND} * | \
		cpio -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/beonex
	${ECHO_CMD} "#!/bin/sh" > ${WRKDIR}/beonex
	${ECHO_CMD} 'cd ${PREFIX}/lib/beonex && exec ./mozilla "$$@"' >> \
		${WRKDIR}/beonex
	${INSTALL_SCRIPT} ${WRKDIR}/beonex ${PREFIX}/bin/
	${LN} -sf \
		${LOCALBASE}/jdk1.3.1/jre/plugin/i386/ns600/libjavaplugin_oji.so\
		${PREFIX}/lib/beonex/plugins/libjavaplugin_oji.so

.include <bsd.port.post.mk>
