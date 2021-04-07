PORTNAME=	ridl
DISTVERSIONPREFIX=	v
DISTVERSION=	g20190530
CATEGORIES=	security

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Tool to check whether the system is affected by various attacks

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	specific to Intel CPUs per https://mdsattacks.com/

LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo

USES=		cmake localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	vusec
GH_TAGNAME=	11b3240
GH_TUPLE=	nothings:stb:1034f5e:stb/stb \
		vurtun:nuklear:509c75b:nuklear/nuklear

LDFLAGS+=	${LOCALBASE}/lib/libsysinfo.so

PLIST_FILES=	bin/mdstool-cli

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/mdstool-cli ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
