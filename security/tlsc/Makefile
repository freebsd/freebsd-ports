PORTNAME=		tlsc
DISTVERSION=		2.0
CATEGORIES=		security
MASTER_SITES=		https://github.com/Zirias/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/download/v${DISTVERSION}

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	TLS connect daemon
WWW=		https://github.com/Zirias/tlsc

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libposercore.so:devel/poser

USES=		compiler:c11 gmake pkgconfig tar:xz

USE_RC_SUBR=	${PORTNAME}

MAKE_ARGS=	V=1
ALL_TARGET=	strip

USERS=		tlsc
GROUPS=		tlsc

PLIST_FILES=	bin/tlsc

.include <bsd.port.mk>
