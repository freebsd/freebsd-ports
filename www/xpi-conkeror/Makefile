# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	conkeror
PORTVERSION=	20150730
CATEGORIES=	www
MASTER_SITES=	http://distfiles.pirateparty.in/ashish/ \
		LOCAL/ashish

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Keyboard-oriented, customizable web browser based on Mozilla XULRunner

LICENSE=	GPLv1 GPLv2 MPL
LICENSE_COMB=	multi

OPTIONS_SINGLE+=	XULRUNNER
OPTIONS_SINGLE_XULRUNNER=	FIREFOX LIBXUL
FIREFOX_DESC?=	Use XULRunner from Firefox port
LIBXUL_DESC?=	Use XULRunner from LibXUL port
OPTIONS_DEFAULT+=	LIBXUL

USES=		desktop-file-utils tar:xz gmake

LIBXUL_USES=	gecko
FIREFOX_USES=	gecko:firefox,32+
ALL_TARGET=	# empty

BUILD_ID=	${ECHO_CMD} -n `whoami`@`hostname`_`date +%s`

post-patch:
		cd ${WRKSRC} && \
			${MV} contrib/conkeror.desktop . && \
			${MV} contrib/man/conkeror.1 . && \
			${RM} -r contrib/debian contrib/dist contrib/man debian tests && \
			${RM} contrib/build.sh contrib/install.sh contrib/mketags.sh \
			contrib/testrun.sh contrib/run-conkeror && \
			${MKDIR} share  && \
			${MV} branding chrome components content \
			contrib defaults locale modules search-engines help \
			style share && \
			${MV} COPYING CREDITS Info.plist chrome.manifest \
			content-policy.manifest share
		${REINPLACE_CMD} -e "s,%%DATADIR%%,${DATADIR},g" ${WRKSRC}/conkeror

post-patch-FIREFOX-on:
		${REINPLACE_CMD} -e "s/xulrunner/firefox/g" ${WRKSRC}/conkeror
		${REINPLACE_CMD} -e "s/XULRUNNER/FIREFOX/g" ${WRKSRC}/conkeror
		${REINPLACE_CMD} -e 's/exec $${FIREFOX}/exec $${FIREFOX} -app/' ${WRKSRC}/conkeror

do-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/libexec/conkeror
		${MKDIR} ${STAGEDIR}${DATADIR}
		cd ${WRKSRC}/share && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}
		${SED} -e "s/BuildID=git/BuildID=$$(${BUILD_ID})/g" \
			-e "s/^Version=\(.*\)$$/Version=\1 (FreeBSD-${OSREL})/g" \
			<${WRKSRC}/application.ini >${STAGEDIR}${DATADIR}/application.ini
		${INSTALL_SCRIPT} ${WRKSRC}/conkeror ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_DATA} ${WRKSRC}/conkeror.desktop ${STAGEDIR}${DESKTOPDIR}
		${INSTALL_PROGRAM} ${WRKSRC}/conkeror-spawn-helper ${STAGEDIR}${PREFIX}/libexec/conkeror/
		${LN} -sf ${PREFIX}/libexec/conkeror/conkeror-spawn-helper ${STAGEDIR}${DATADIR}/
		${INSTALL_MAN} ${WRKSRC}/conkeror.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
