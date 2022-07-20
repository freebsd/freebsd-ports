PORTNAME=	i2p
DISTVERSION=	0.9.48
CATEGORIES=	security java net-p2p
MASTER_SITES=	http://download.i2p2.de/releases/${PORTVERSION}/
DISTNAME=	i2psource_${PORTVERSION}

MAINTAINER=	m.muenz@gmail.com
COMMENT=	Anonymizing network

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_DISTFILES=	i2psource_${PORTVERSION}${EXTRACT_SUFX}

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	i2p libwrapper.so library binary only available for i386 and amd64

BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.a:math/gmp
LIB_DEPENDS=	libiconv.so:converters/libiconv

USES=		cpe gettext tar:bz2
CPE_VENDOR=	geti2p

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USE_RC_SUBR=	i2p
USE_ANT=	yes
USE_JAVA=	yes
NO_ARCH=	yes
JAVA_BUILD=	jdk
USE_LOCALE=	en_US.UTF-8
ALL_TARGET=	updater tarball

SUB_FILES=	wrapper.sh

PORTDATA=	*
PLIST_FILES=	sbin/i2prouter

post-patch:
# postinstall.sh SHOULD only do post installation house keeping
	@${REINPLACE_CMD} -E \
		-e 's|./i2prouter[[:space:]]+start||' \
		${WRKSRC}/installer/resources/postinstall.sh
	@${REINPLACE_CMD} -E \
		-e 's|%INSTALL_PATH|$${HOME}/i2p|' \
		-e 's|%USER_HOME|$${HOME}|' \
		${WRKSRC}/installer/resources/i2prouter \
		${WRKSRC}/installer/resources/runplain.sh

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/i2p.tar.bz2 ${STAGEDIR}${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/i2pupdate.zip ${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh ${STAGEDIR}${PREFIX}/sbin/i2prouter

.include <bsd.port.mk>
