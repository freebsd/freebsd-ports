# New ports collection makefile for:	i2p
# Date created:		Sun Jan  9 05:05:02 UTC 2005
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	i2p
PORTVERSION=	0.7.4
CATEGORIES=	net-p2p java security
MASTER_SITES=	http://mirror.i2p2.de/:i2p \
		${MASTER_SITE_GOOGLE_CODE}:i2p \

		SF/jetty/OldFiles:jetty

DISTFILES=	\
		i2psource_${PORTVERSION}${EXTRACT_SUFX}:i2p \
		${JETTY_DISTFILE}:jetty
EXTRACT_ONLY=	i2psource_${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	An anonymizing network

BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.a:${PORTSDIR}/math/libgmp4
RUN_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

USE_BZIP2=	yes
USE_RC_SUBR=	i2p.sh

JAVA_BUILD=	jdk
USE_JAVA=	yes
JAVA_VERSION=	1.5+
JAVA_OS=	native
USE_ANT=	yes

ALL_TARGET=	\
		updater \
		tarball

.ifndef(NOPORTDOCS)
ALL_TARGET+=	javadoc
.endif

JAVADOC_WRKSRC=	${WRKSRC}/build/javadoc

.ifndef(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_DIRS=	\
		%%DATADIR%%
PLIST_FILES=	\
		sbin/i2prouter \
		%%DATADIR%%/i2p.tar.bz2 \
		%%DATADIR%%/i2pupdate.zip

JETTY_DISTFILE=	jetty-5.1.12.zip

post-extract:
	@${MKDIR} ${WRKSRC}/apps/jetty/
	@${CP} -f ${DISTDIR}/${JETTY_DISTFILE} ${WRKSRC}/apps/jetty/

post-patch:
	@${SED} \
		-e "s|%%DATADIR%%|${DATADIR}|" \
		${FILESDIR}/wrapper.sh > ${WRKDIR}/wrapper.sh
# postinstall.sh SHOULD only do post installation house keeping
	@${REINPLACE_CMD} -E \
		-e 's|./i2prouter[[:space:]]+start||' \
		${WRKSRC}/installer/resources/postinstall.sh

do-install:
	@${MKDIR} ${DATADIR}
# install
	@${INSTALL_DATA} ${WRKSRC}/i2p.tar.bz2 \
		${DATADIR}/
# update
	@${INSTALL_DATA} ${WRKSRC}/i2pupdate.zip \
		${DATADIR}/
# wrapper
	@${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
		${PREFIX}/sbin/i2prouter
# doc
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/readme*.html ${DOCSDIR}
# line taken from textproc/xerces-j maintained by hq@FreeBSD.org
	@cd ${JAVADOC_WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DOCSDIR}/{}" \; && \
		${FIND} * -not -type d -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>
