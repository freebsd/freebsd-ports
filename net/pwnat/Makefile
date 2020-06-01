# $FreeBSD$

PORTNAME=	pwnat
PORTVERSION=	g20171222
CATEGORIES=	net

MAINTAINER=	egypcio@FreeBSD.org
COMMENT=	NAT punching tool based on udptunnel

LICENSE=	GPLv3

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	Fails to patch while running in embedded systems

USES=		gmake
USE_RC_SUBR=	${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	samyk
GH_TAGNAME=	5de412c

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's/CC=.*/CC=${CC}/g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's/CFLAGS=.*/CFLAGS=${CFLAGS}/g' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}/${PREFIX}/bin
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
