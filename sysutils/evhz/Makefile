PORTNAME=	evhz
DISTVERSION=	g20210920
DISTVERSIONSUFFIX=	-0-g35b7526
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://git.sr.ht/~iank/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool for measuring evdev event rate (mouse polling rate)
WWW=		https://git.sr.ht/~iank/evhz

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto

USES=		localbase uidfix
MAKEFILE=	bsd.prog.mk
MAKE_ARGS=	PROG="${PORTNAME}" MAN= BINDIR="${PREFIX}/bin"
PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
