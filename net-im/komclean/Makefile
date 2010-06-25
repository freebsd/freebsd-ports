# Ports collection makefile for: komclean
# Date created:		23 March 2010
# Whom: 		smyru@heron.pl
#
# $FreeBSD$
#

PORTNAME=	komclean
PORTVERSION=	1.1.0
CATEGORIES=	net-im
MASTER_SITES=	http://dl.sharesource.org/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	smyru@heron.pl
COMMENT=	Web based LysKOM client

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/Copyright.txt

USE_GMAKE=	yes
USE_XORG=	x11 xext xextproto xpm
INSTALLS_ICONS=	yes
MAN1=		komclean

WRKSRC=		${WRKDIR}/${PKGNAME}
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV=	CPPFLAGS="${CXXFLAGS}" LDFLAGS="${LDFLAGS}"

DESKTOP_ENTRIES="KOMclean" \
		"${COMMENT}" \
		"komclean.xpm" \
		"komclean" \
		"" \
		${FALSE}

.include <bsd.port.pre.mk>

pre-everything::
.ifndef(WITH_PORT)
	@${ECHO_MSG}
	@${ECHO_MSG} "Define WITH_PORT=[port number] to change default port 8080"
	@${ECHO_MSG}
.endif

pre-build:
.ifdef(WITH_PORT)
	${REINPLACE_CMD} 's,8080,'${WITH_PORT}',' ${WRKSRC}/src/webui/httpserver.cpp
.endif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/komclean ${PREFIX}/bin
	@${MKDIR} ${DATADIR}/html/img
	@${INSTALL_DATA} ${WRKSRC}/html/img/*.* ${DATADIR}/html/img
	@${INSTALL_DATA} ${WRKSRC}/html/*.* ${DATADIR}/html
	@${INSTALL_DATA} ${WRKSRC}/icon/icon_normal.xpm ${PREFIX}/share/pixmaps/komclean.xpm
	@${INSTALL_MAN} ${WRKSRC}/komclean.1 ${MANPREFIX}/man/man1/komclean

.include <bsd.port.post.mk>
