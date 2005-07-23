# New ports collection makefile for:	xmule
# Date created:		Tue Mar 11 05:06:20 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmule
DISTVERSION=	1.10.0a
CATEGORIES=	net
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITES=	http://download.berlios.de/%SUBDIR%/
MASTER_SITE_SUBDIR=	xmule
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Port of eMule eDonkey P2P client using wxWindows class library

BUILD_DEPENDS=	${LOCALBASE}/lib/libcryptopp.a:${PORTSDIR}/security/cryptopp
LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2 \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

BROKEN=		Incomplete pkg-plist
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehier \
		gnomehack \
		gnomeprefix
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext \
		--with-cryptopp-prefix=${LOCALBASE} \
		--with-gtk-prefix=${X11BASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--enable-debug \
		--with-wx-config=${WX_CONFIG}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS} -L${LOCALBASE}/lib"
MAKE_ENV=	CC="${CC}" CXX="${CXX}"

# for debugging purposes
STRIP=

WX_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config

FILES_ATOLL_PATCH=	src/Preferences.cpp \
			src/otherfunctions.cpp
FILES_STDINT_PATCH=	\
			intl/loadmsgcat.c \
			src/ClientList.h \
			src/sockets.h

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-patch:
# it works for FreeBSD as well
	@${REINPLACE_CMD} -E \
		-e 's|(Linux)|FreeBSD/\1|' \
		${WRKSRC}/src/*.cpp
# update documentation with correct prefix
	@${REINPLACE_CMD} -E \
		-e 's|/usr/X11R6/(bin/${PORTNAME}-ed2k-handler)|${PREFIX}/\1|' \
		${WRKSRC}/ED2K-Links.HOWTO
# use BSD_INSTALL_* macros
	@${REINPLACE_CMD} -E \
		-e 's|cp -f|${INSTALL_DATA}|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E \
		-e 's|cp -p|${INSTALL_DATA}|' \
		${WRKSRC}/po/Makefile.in.in
# fix mkinstalldirs location
# uphold CXX{,FLAGS}
	${FIND} ${WRKSRC} -name "Makefile*" -type f -print0 | \
		${XARGS} -0 \
		${REINPLACE_CMD} -E \
		-e 's,^(MKINSTALLDIRS|mkinstalldirs).*$$,\1=${INSTALL_WRKSRC}/mkinstalldirs,' \
		-e 's|g\+\+|${CXX}|' \
		-e 's|-O3|${CXXFLAGS}|'
# use correct FreeBSD atoll() prototype
.for file in ${FILES_ATOLL_PATCH}
	@${REINPLACE_CMD} -E \
		-e 's|atoll[[:space:]]*\([[:space:]]*char|atoll(const char|' \
		${WRKSRC}/${file}
.endfor
# stdint.h -> inttypes.h
.for file in ${FILES_STDINT_PATCH}
	@${REINPLACE_CMD} -E \
		-e 's|<stdint.h>|<inttypes.h>|' \
		${WRKSRC}/${file}
.endfor

pre-configure:
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | \
		${XARGS} -x -n 10 \
		${REINPLACE_CMD} -E \
		-e 's!^(AUTOCONF|AUTOHEADER|AUTOMAKE|ACLOCAL).*$$!\1=${TRUE}!'
	@${REINPLACE_CMD} -E \
		-e 's|^(CXXFLAGS.*)$$|\1 -I${LOCALBASE}/include|' \
		${WRKSRC}/xLibs/xrc/xrc.make.in

post-install:
# install xmule binary
	@${INSTALL_PROGRAM} \
		${WRKSRC}/${PORTNAME} \
		${PREFIX}/bin
# do not install a generic named ed2k binary
# install it under a more specific name
	@${INSTALL_PROGRAM} \
		${WRKSRC}/ed2k.xmule-2.0 \
		${PREFIX}/bin/${PORTNAME}-ed2k-handler

.include <bsd.port.post.mk>
