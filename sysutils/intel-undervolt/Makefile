PORTNAME=	intel-undervolt
DISTVERSION=	1.7
CATEGORIES=	sysutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Intel CPU undervolting tool
WWW=		https://github.com/kitsunyan/intel-undervolt

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	specifically for Haswell and newer Intel CPUs

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	kitsunyan
GNU_CONFIGURE=	yes

PIE_UNSAFE=	yes

MAKE_ARGS=	CC="${CC}" \
		SYSCONFDIR="${PREFIX}/etc"

PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}.conf.sample"

post-patch:
	${REINPLACE_CMD} "s|/bin/bash|${LOCALBASE}/bin/bash|g" ${WRKSRC}/config.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample

.include <bsd.port.mk>
