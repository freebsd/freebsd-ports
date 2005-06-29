# New ports collection makefile for:	nvu
# Date created:		August 21, 2004
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	nvu
DISTVERSION=	1.0
CATEGORIES=	www
MASTER_SITES=	http://cvs.nvu.com/download/
DISTNAME=	${PORTNAME}-${DISTVERSION}-sources

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	A complete Web Authoring System similar to Dreamweaver or Frontpage

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_PERL5=	yes
USE_GNOME=	gtk20 libidl
USE_REINPLACE=	yes
USE_GMAKE=	yes
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
NVU=		${PORTNAME}-${DISTVERSION}
FAKEDIR=	${WRKDIR}/FAKE
WRKSRC=		${WRKDIR}/mozilla
PLIST=		${WRKDIR}/plist
MAKEFILE=	client.mk
ALL_TARGET=	build_all
PKG_CONFIGS=	nvu-gtkmozembed.pc nvu-js.pc nvu-nspr.pc \
		nvu-nss.pc nvu-plugin.pc nvu-xpcom.pc
EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude */CVS/*

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-config_make-jars.pl
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "Enable -O2 optimizations by defining"
	@${ECHO_MSG} "WITH_OPTIMIZED_CFLAGS"
	@${ECHO_MSG}
.endif

post-patch:
# Remove so we can actaully find programs that are not in /usr/bin
	@${RM} -f ${WRKSRC}/config.status ${WRKSRC}/config.cache
	@${SED} -e 's|%%NVUDIR%%|${PREFIX}/lib/${NVU}|g ; \
		s|%%PREFIX%%|${PREFIX}|g ; \
		s|%%X11BASE%%|${X11BASE}|g' \
		< ${MASTERDIR}/pkg-install.in > ${PKGINSTALL}
	@${SED} -e 's|%%NVUDIR%%|${PREFIX}/lib/${NVU}|g' \
		< ${MASTERDIR}/pkg-deinstall.in > ${PKGDEINSTALL}
	@${SED} -e 's|%%CC%%|${CC}|; s|%%CXX%%|${CXX}|; \
		s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|; \
		s|%%CFLAGS%%|${CFLAGS}|; \
		s|%%CXXFLAGS%%|${CXXFLAGS}|; \
		s|%%PREFIX%%|${FAKEDIR}|; \
		s|%%LOCALBASE%%|${LOCALBASE}|' \
		${FILESDIR}/mozconfig.in >${WRKSRC}/.mozconfig
# Stupid workaround..
.for f in toolkit/components/Makefile.in toolkit/components/gnome/Makefile.in
	@${ECHO_CMD} "LDFLAGS += -L${LOCALBASE}/lib" >> ${WRKSRC}/${f}
.endfor
.if defined(WITH_DEBUG)
	@${ECHO_CMD} "ac_add_options  --enable-debug" >> ${WRKSRC}/.mozconfig
	@${ECHO_CMD} "ac_add_options  --disable-strip" >> ${WRKSRC}/.mozconfig
.else
	@${ECHO_CMD} "ac_add_options  --disable-debug" >> ${WRKSRC}/.mozconfig
	@${ECHO_CMD} "ac_add_options  --enable-strip" >> ${WRKSRC}/.mozconfig
.endif
.if defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_CMD} "ac_add_options --enable-optimize=-O2" >> ${WRKSRC}/.mozconfig
.endif
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g ; \
		s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/nsprpub/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/nsprpub/configure \
		${WRKSRC}/security/coreconf/FreeBSD.mk \
		${WRKSRC}/js/src/Makefile.in

pre-install:
	${RM} -rf ${PLIST} ${FAKEDIR}
	${TOUCH} -f ${PLIST}
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		 ${MAKEFILE} ${MAKE_ARGS} install
	${ECHO_CMD} bin/nvu >> ${PLIST}
	${ECHO_CMD} bin/nvu-config >> ${PLIST}
	cd ${FAKEDIR}/lib/${NVU} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|lib/${NVU}/|' >> ${PLIST} \
			&& ${FIND} -d * -type d | \
			${SED} -e 's:^:@dirrm lib/${NVU}/:' >> ${PLIST}
	${ECHO_CMD} @dirrm lib/${NVU} >> ${PLIST}
.for p in ${PKG_CONFIGS}
	${ECHO_CMD} ${p:S|^|libdata/pkgconfig/|} >> ${PLIST}
.endfor
	cd ${FAKEDIR}/include/${NVU} && ${FIND} -s * -type f -o -type l | \
		${SED} -e 's|^|include/${NVU}/|' >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm include/${NVU}/|' >> ${PLIST}
	${ECHO_CMD} @dirrm include/${NVU} >> ${PLIST}

do-install:
	${REINPLACE_CMD} -e 's|${FAKEDIR}|${PREFIX}|' \
		${FAKEDIR}/bin/* \
		${FAKEDIR}/lib/pkgconfig/*
	${RM} -f ${FAKEDIR}/bin/*.bak ${FAKEDIR}/lib/pkgconfig/*.bak
	${MKDIR} ${PREFIX}/lib/${NVU}
	${CHMOD} 755 ${PREFIX}/lib/${NVU}
	${INSTALL_SCRIPT} ${FAKEDIR}/bin/* ${PREFIX}/bin
	if [ ! -d ${PREFIX}/libdata/pkgconfig ]; then \
		${MKDIR} ${PREFIX}/libdata/pkgconfig ; \
	fi
.for i in ${PKG_CONFIGS}
	${INSTALL_DATA} ${FAKEDIR}/lib/pkgconfig/${i} ${PREFIX}/libdata/pkgconfig/
.endfor
	cd ${FAKEDIR}/lib/${NVU} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/lib/${NVU}
	cd ${FAKEDIR}/include/${NVU} && ${FIND} . | \
		${CPIO} -pdm -L -R ${LIBOWN}:${LIBGRP} ${PREFIX}/include/${NVU}

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.post.mk>
