# Created by: Klaus Aehlig <aehlig@linta.de>
# $FreeBSD$

PORTNAME=	uzbl
DISTVERSION=	0.0.0.${GITDATE}
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.linta.de/distfiles/

MAINTAINER=	aehlig@linta.de
COMMENT=	Web interface tools which adhere to the unix philosophy

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwebkitgtk-1.0.so:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	socat:${PORTSDIR}/net/socat \
		dmenu:${PORTSDIR}/x11/dmenu

USES=		gmake pkgconfig
USE_GNOME=	gtk20 pygtk2
USE_LDCONFIG=	yes
USE_PYTHON=	2

GITDATE=	2012.05.14
GITVERSION=	228bc38

WRKSRC=		${WRKDIR}/Dieterbe-uzbl-${GITVERSION}

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	AUTHORS README COMMUNITY CONTRIBUTING FAQ INSTALL TODO config-syntax \
		multiple-instances-management performance url-editing config.h vim
.endif

.if !defined(NOPORTDATA)
PORTDATA=	examples
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" \
		${WRKSRC}/examples/config/config \
		${WRKSRC}/bin/uzbl-browser \
		${WRKSRC}/bin/uzbl-event-manager
	@${REINPLACE_CMD} -e "s|share/uzbl|${DATADIR_REL}|" \
		${WRKSRC}/examples/config/config \
		${WRKSRC}/bin/uzbl-browser \
		${WRKSRC}/bin/uzbl-event-manager
	@${REINPLACE_CMD} -e "s|/usr/share/uzbl|${DATADIR}|" \
		${WRKSRC}/bin/uzbl-tabbed
	@${REINPLACE_CMD} -e "s|/usr/bin/env python2|/usr/bin/env ${PYTHON_VERSION}|" \
		${WRKSRC}/bin/uzbl-event-manager

post-build:
	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" \) -exec ${RM} -f {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uzbl-core ${PREFIX}/bin
.for f in uzbl-event-manager uzbl-browser uzbl-tabbed
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/config.h ${DOCSDIR}
.for f in COMMUNITY CONTRIBUTING FAQ INSTALL TODO config-syntax \
		multiple-instances-management performance url-editing
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}/${f}
.endfor
.for f in AUTHORS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f}
.endfor
	(cd ${WRKSRC}/extras && ${COPYTREE_SHARE} vim ${DOCSDIR})
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}/examples/data/dforms ${DATADIR}/examples/config
.for f in data/bookmarks \
	data/dforms/bbs.archlinux.org \
	config/style.css data/uzbl.png
		${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DATADIR}/examples/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/config/config ${DATADIR}/examples/config/config
	(cd ${WRKSRC}/examples/data && \
		${COPYTREE_BIN} plugins ${DATADIR}/examples/data/)
	(cd ${WRKSRC}/examples/data && \
		${COPYTREE_BIN} scripts ${DATADIR}/examples/data/)
.endif

.include <bsd.port.mk>
