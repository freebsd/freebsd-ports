# Created by: Paolo Pisati <flag@gufi.org>
# $FreeBSD$

PORTNAME=	wmnd
PORTVERSION=	0.4.17
CATEGORIES=	net
MASTER_SITES=	http://www.thregr.org/~wavexx/software/wmnd/releases/
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Improved network monitoring dock app (with tons of features)

LICENSE=	GPLv2

OPTIONS_DEFINE=	EXAMPLES

USES=		gmake
USE_XORG=	ice sm x11 xext xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dummy-driver

PORTEXAMPLES=	wmndrc
PLIST_FILES=	bin/wmnd \
		man/man1/wmnd.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmnd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/wmnd.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/wmndrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
