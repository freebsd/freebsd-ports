# Created by: Tzanetos Balitsaris <tzabal@it.teithe.gr>
# $FreeBSD$

PORTNAME=	jitsi
PORTVERSION=	2.3
CATEGORIES=	net-im java
MASTER_SITES=	http://aetos.it.teithe.gr/~tzabal/ports/jitsi/ \
		http://www.c-s.li/ports/
DISTNAME=	jitsi-master-084e2b42b5

MAINTAINER=	tzabal@it.teithe.gr
COMMENT=	Open source IM and VoIP application

LICENSE=	LGPL21

USES=		zip
USE_JAVA=	yes
USE_ANT=	yes
MAKE_ARGS=	rebuild
USE_LDCONFIG=	${PREFIX}/lib/jitsi/lib/native

ONLY_FOR_ARCHS=	i386 amd64

DESKTOP_ENTRIES="Jitsi" \
		"VoIP and Instant Messenger" \
		"${PREFIX}/share/pixmaps/jitsi.png" \
		"${PORTNAME}" \
		"Network;InstantMessaging;VideoConference;Java;" \
		true

do-install:
	@${ECHO_CMD} ">> Creating Jitsi directories..."
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/jitsi/sc-bundles
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/jitsi/lib/bundle
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/jitsi/lib/native
# Bundles (Jitsi modules)
	@${ECHO_CMD} ">> Installing bundles (Jitsi modules)..."
	@cd ${WRKSRC}/sc-bundles && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/lib/jitsi/sc-bundles
	@${RM} ${STAGEDIR}${PREFIX}/lib/jitsi/sc-bundles/*slick*.jar
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/jitsi/sc-bundles/os-specific
# Library JARs
	@${ECHO_CMD} ">> Installing library jars..."
	@cd ${WRKSRC}/lib/bundle && ${COPYTREE_SHARE} . \
		${STAGEDIR}${PREFIX}/lib/jitsi/lib/bundle "! -name junit.jar"
	@cd ${WRKSRC}/lib && ${COPYTREE_SHARE} "felix.jar jdic-all.jar \
		felix.client.run.properties logging.properties" \
			${STAGEDIR}${PREFIX}/lib/jitsi/lib
# Native libraries
	@${ECHO_CMD} ">> Installing native (${ARCH}) libraries..."
	@cd ${WRKSRC}/lib/native/freebsd${ARCH:S/i386//:S/amd/-/:S/x86_/-/} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/jitsi/lib/native
# Wrapper script to run Jitsi
	@${ECHO_CMD} ">> Installing wrapper script..."
	${INSTALL_SCRIPT} ${FILESDIR}/jitsi.sh ${STAGEDIR}${PREFIX}/bin/jitsi
# Manual page
	@${ECHO_CMD} ">> Installing the manual page..."
	${INSTALL_MAN} ${FILESDIR}/jitsi.1 ${STAGEDIR}${MANPREFIX}/man/man1
# Desktop related
	@${ECHO_CMD} ">> Installing Jitsi's logo..."
	${INSTALL_DATA} ${WRKSRC}/resources/images/logo/sc_logo_128x128.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/jitsi.png

.include <bsd.port.mk>
