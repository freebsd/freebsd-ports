# New ports collection makefile for:   gnet-glib2
# Date created:        15 February 2003
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnet
PORTVERSION=	1.1.9
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.gnetlibrary.org/src/
PKGNAMESUFFIX=	-glib2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A simple network library built upon Glib-2

USE_REINPLACE=	yes
USE_GNOME=	gnomehack glib20
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-glib2

MAN1=	gnet-glib2-config.1

post-patch:
# remove "release" information from lib name
	@${REINPLACE_CMD} -E -e 's|-release[ ]+\$$\(LT_RELEASE\)||g' \
		${WRKSRC}/src/Makefile.in
# don't install gnet-config script with odd name. We will install it ourselves
	@${REINPLACE_CMD} -E -e 's|^(install-exec-am:).+$$|\1|' \
		${WRKSRC}/Makefile.in
# don't install any of the config files.  We will do it ourselves.
	@${REINPLACE_CMD} -E -e 's|^(install-data-am:).+$$|\1|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E -e 's|^[[:space:]]+install-pkgconfigDATA$$||' \
		${WRKSRC}/Makefile.in
# don't install the manpage.  We will do it ourselves.
	@${REINPLACE_CMD} -E -e 's|^(install-data-am:).+$$|\1 install-data-local|' \
		${WRKSRC}/doc/Makefile.in
# install configincludedir correctly
	@${REINPLACE_CMD} -E -e 's|^(configincludedir).+$$|\1=\$$\(pkgincludedir\)-glib2|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-lc_r|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/gnet-config ${PREFIX}/bin/gnet-glib2-config
	@${MKDIR} ${PREFIX}/share/aclocal
	@${INSTALL_DATA} ${WRKSRC}/gnet.m4 ${PREFIX}/share/aclocal/gnet-glib2.m4
	@${INSTALL_DATA} ${WRKSRC}/gnetconfig.h \
		${PREFIX}/include/gnet-glib2
	@${MKDIR} ${PREFIX}/libdata/pkgconfig
	@${INSTALL_DATA} ${WRKSRC}/gnet.pc \
		${PREFIX}/libdata/pkgconfig/gnet-glib2.pc
	@${MKDIR} ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/doc/gnet-config.1 \
		${PREFIX}/man/man1/gnet-glib2-config.1

.include <bsd.port.mk>
