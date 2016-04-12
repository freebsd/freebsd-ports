# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	i2p
PORTVERSION=	0.9.16
CATEGORIES=	security java net-p2p
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTVERSION} \
		http://download.i2p2.no/releases/${PORTVERSION}/ \
		http://download2.geti2p.com/${PORTVERSION}/ \
		http://download.geti2p.com/${PORTVERSION}/ \
		http://download.i2p2.de/releases/${PORTVERSION}/ \
		https://launchpad.net/i2p/trunk/${PORTVERSION}/+download/ \
		https://googledrive.com/host/0B4jHEq5G7_EPWV9UeERwdGplZXc/${PORTVERSION}/
DISTFILES=	i2psource_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Anonymizing network

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_DISTFILES=	i2psource_${PORTVERSION}${EXTRACT_SUFX}

BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.a:math/gmp
LIB_DEPENDS=	libiconv.so:converters/libiconv
RUN_DEPENDS=	unzip:archivers/unzip

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	i2p libwrapper.so library binary only available for i386 and amd64

OPTIONS_DEFINE=	DOCS

USES=		gettext tar:bzip2
USE_RC_SUBR=	i2p

USE_ANT=	yes
USE_JAVA=	yes
JAVA_BUILD=	jdk
JAVA_VERSION=	1.6+

ALL_TARGET=	\
		updater \
		tarball
MAKE_ENV=	LANG=en_US.UTF-8

PORTDATA=	*

PLIST_FILES=	\
		sbin/i2prouter

SUB_FILES=	wrapper.sh

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
ALL_TARGET+=	javadoc

PORTDOCS=	*

JAVADOC_WRKSRC=	${WRKSRC}/build/javadoc
.endif

.include <bsd.port.pre.mk>

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
# install
	@${INSTALL_DATA} ${WRKSRC}/i2p.tar.bz2 \
		${STAGEDIR}${DATADIR}/
# update
	@${INSTALL_DATA} ${WRKSRC}/i2pupdate.zip \
		${STAGEDIR}${DATADIR}/
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${STAGEDIR}${PREFIX}/sbin/i2prouter
# doc
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/installer/resources/readme/readme*.html ${STAGEDIR}${DOCSDIR}
# line taken from textproc/xerces-j maintained by hq@FreeBSD.org
	@cd ${JAVADOC_WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${DOCSDIR}/{}" \; && \
		${FIND} * -not -type d -exec ${INSTALL_DATA} "{}" "${STAGEDIR}${DOCSDIR}/{}" \;
.endif

.include <bsd.port.post.mk>
