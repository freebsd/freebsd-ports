PORTNAME=	wmnd
PORTVERSION=	0.4.18
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.thregr.org/~wavexx/software/wmnd/releases/

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Improved network monitoring dock app (with tons of features)
WWW=		https://www.thregr.org/~wavexx/software/wmnd/

LICENSE=	GPLv2

USES=		gmake xorg

USE_XORG=	ice sm x11 xext xpm
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dummy-driver --enable-drivers=freebsd_sysctl

PLIST_FILES=	bin/wmnd \
		share/man/man1/wmnd.1.gz
PORTEXAMPLES=	wmndrc

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/wmnd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/wmnd.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/wmndrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
