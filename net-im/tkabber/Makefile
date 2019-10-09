# Created by: Alexander Timoshenko <gonzo@univ.kiev.ua>
# $FreeBSD$

PORTNAME=	tkabber
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	net-im tcl tk
MASTER_SITES=	http://files.jabber.ru/tkabber/

MAINTAINER=	mp39590@gmail.com
COMMENT=	Tcl/Tk based jabber client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	tcllib>=1.2:devel/tcllib \
		bwidget>=1.4:x11-toolkits/bwidget

OPTIONS_DEFINE=	DOCS EXAMPLES IPV6 SOUND TDOM TKCON TKTRAY TLS
OPTIONS_DEFAULT=	TLS

CONFLICTS=	tkabber-devel-[0-9]*

USES=		shebangfix tar:xz
SHEBANG_FILES=	contrib/extract-translations/extract.tcl

IPV6_USES=	tk:86+
IPV6_USES_OFF=	tk:85+
SOUND_RUN_DEPENDS=	snack>=2.2.10:audio/snack
TDOM_DESC=	Use more efficient tDOM parser for XML
TDOM_RUN_DEPENDS=	tDOM>=0.8.0:www/tdom
TKCON_DESC=	Install devel/tkcon for interactive debugging
TKCON_RUN_DEPENDS=	tkcon>=2.3:devel/tkcon
TKTRAY_DESC=	Install x11-toolkits/tktray for system tray support
TKTRAY_RUN_DEPENDS=	tktray>=1.3:x11-toolkits/tktray
TLS_RUN_DEPENDS=	tcltls>=1.4.1:devel/tcltls

WRKSRC=		${WRKDIR}/${DISTNAME}
NO_BUILD=	yes
NO_ARCH=	yes

SUBDIRS=	contrib emoticons ifacetk mclistbox \
		msgs pixmaps plugins sounds tclxmpp trans

do-install:
	${ECHO_CMD} -e "#!/bin/sh\nexec ${WISH} ${DATADIR}/tkabber.tcl \
		-name tkabber \"\$$@\"\n" > ${WRKDIR}/tkabber.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tkabber.sh ${STAGEDIR}${PREFIX}/bin/tkabber
	${ECHO_CMD} -e "#!/bin/sh\nexec ${WISH} ${DATADIR}/tkabber-remote.tcl \
		-name tkabber-remote \"\$$@\"\n" > ${WRKDIR}/tkabber-remote.sh
	${INSTALL_SCRIPT} ${WRKDIR}/tkabber-remote.sh ${STAGEDIR}${PREFIX}/bin/tkabber-remote
	${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} ${WRKSRC}/*.tcl ${STAGEDIR}${DATADIR}
.for i in ${SUBDIRS}
	${CP} -R ${WRKSRC}/${i} ${STAGEDIR}${DATADIR}
.endfor

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in tkabber.html tkabber.xml
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
