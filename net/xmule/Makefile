# New ports collection makefile for:	xmule
# Date created:		Tue Mar 11 05:06:20 UTC 2003
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmule
PORTVERSION=	1.8.1
CATEGORIES=	net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmule

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Port of eMule eDonkey P2P client using wxWindows class library

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2 \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk2
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

BROKEN=	SIGSEGVs too easily. Help to fix it is highly appreciated

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
		--with-gtk-prefix=${X11BASE} \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-libintl-prefix=${LOCALBASE} \
		--enable-debug \
		--with-wx-config=${WX_CONFIG}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${PTHREAD_CFLAGS}" \
		LDFLAGS="${LDFLAGS} ${PTHREAD_LIBS}"

# for debugging purposes
STRIP=

WX_CONFIG?=	${X11BASE}/bin/wxgtk2-2.4-config

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

pre-configure:
	@${FIND} ${WRKSRC} -type f -name "Makefile.in" | \
		${XARGS} -x -n 10 \
		${REINPLACE_CMD} -E \
		-e 's!^(AUTOCONF|AUTOHEADER|AUTOMAKE|ACLOCAL).*$$!\1=${TRUE}!'

post-install:
# install xmule binary
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${PREFIX}/bin
# do not install a generic named ed2k binary
# install it under a more specific name
	@${INSTALL_PROGRAM} ${WRKSRC}/src/ed2k \
		${PREFIX}/bin/${PORTNAME}-ed2k-handler

.include <bsd.port.mk>
