# New ports collection makefile for:   gnet
# Date created:        16 February 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnet
PORTVERSION=	1.1.9
CATEGORIES=	net
MASTER_SITES=	http://www.gnetlibrary.org/src/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A simple network library built upon Glib

USE_AUTOTOOLS=	libtool:22
USE_GNOME=	gnomehack glib12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=	gnet-config.1

post-patch:
# fix pthreads detection
	@${REINPLACE_CMD} -E -e 's,-lpthread|-lc_r,${PTHREAD_LIBS},' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
# remove "release" information from lib name
	@${REINPLACE_CMD} -E -e 's|-release[ ]+\$$\(LT_RELEASE\)||g' \
		${WRKSRC}/src/Makefile.in
# don't install gnet-config script with odd name. We will install it ourselves
	@${REINPLACE_CMD} -E -e 's|^(install-exec-am:).+$$|\1|' \
		${WRKSRC}/Makefile.in
# install gnet-config.1 man (not another name). Revise at EVERY port update
	@${REINPLACE_CMD} -e 's|\$$\$$inst|\$$\$$file|g' \
		${WRKSRC}/doc/Makefile.in
# install configincludedir correctly
	@${REINPLACE_CMD} -E -e 's|^(configincludedir).+$$|\1=\$$\(pkgincludedir\)|' \
		${WRKSRC}/Makefile.in

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/gnet-config ${PREFIX}/bin

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/html/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
