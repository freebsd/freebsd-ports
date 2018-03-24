# Created by: Guangyuan Yang <ygy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	websocketd
DISTVERSION=	0.3.0
CATEGORIES=	www
MASTER_SITES=	https://github.com/joewalnes/${PORTNAME}/releases/download/v${DISTVERSION}/
DISTNAME=	${PORTNAME}-${DISTVERSION}-freebsd_${ARCH:S/i386/386/:S/x86_64/amd64/}

MAINTAINER=	ygy@FreeBSD.org
COMMENT=	Access any command-line tool via a WebSocket

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS= amd64 i386

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/${PORTNAME}

NO_BUILD=	yes
USES=		zip

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
