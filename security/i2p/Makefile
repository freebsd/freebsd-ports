# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i2p
DISTVERSION=	0.9.40
CATEGORIES=	security java net-p2p
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTVERSION} \
		http://download.i2p2.no/releases/${PORTVERSION}/ \
		http://download2.geti2p.com/${PORTVERSION}/ \
		http://download.geti2p.com/${PORTVERSION}/ \
		http://download.i2p2.de/releases/${PORTVERSION}/ \
		https://launchpad.net/i2p/trunk/${PORTVERSION}/+download/ \
		https://googledrive.com/host/0B4jHEq5G7_EPWV9UeERwdGplZXc/${PORTVERSION}/
DISTNAME=	i2psource_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
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

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

USES=		gettext tar:bzip2
USE_RC_SUBR=	i2p
USE_ANT=	yes
USE_JAVA=	yes
NO_ARCH=	yes
JAVA_BUILD=	jdk
USE_LOCALE=	en_US.UTF-8
ALL_TARGET=	updater tarball

SUB_FILES=	wrapper.sh

PORTDATA=	*
PORTDOCS=	*
PLIST_FILES=	sbin/i2prouter

OPTIONS_DEFINE=	DOCS

DOCS_ALL_TARGET=	javadoc

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

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/installer/resources/readme/readme*.html ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/build/javadoc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
