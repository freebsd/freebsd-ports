# Ports collection makefile for:	stardict2
# Date created:			13 April 2003
# Whom:				Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	stardict
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	stardict-${PORTVERSION}.tar.bz2
DIST_SUBDIR=	stardict

MAINTAINER=	ld@FreeBSD.org.cn
COMMENT=	A cross-platform and international dictionary written in Gtk2

BROKEN=		"Does not compile"

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix libgnomeui
USE_REINPLACE=	yes

MAN1=		stardict.1

post-patch:
# gcc 2.95 does not know std::string::clear()
	@${REINPLACE_CMD} -e 's|.clear()|.erase()|' \
		${WRKSRC}/src/docklet.cpp ${WRKSRC}/src/floatwin.cpp \
		${WRKSRC}/src/selection.cpp

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
