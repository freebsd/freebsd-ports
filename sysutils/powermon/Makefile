PORTNAME=	powermon
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	sysutils

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Displays the CPUs current power consumption
WWW=		https://github.com/Yamagi/powermon

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	specific to recent x86 processors

LIB_DEPENDS=	libcpuid.so:sysutils/libcpuid

USES=		gmake ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	yamagi
MAKE_ENV=	NCURSESLIBS="${NCURSESLIBS}" VERBOSE=1

PLIST_FILES=	share/man/man8/powermon.8.gz sbin/powermon

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/release/powermon \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${INSTALL_WRKSRC}/misc/powermon.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
