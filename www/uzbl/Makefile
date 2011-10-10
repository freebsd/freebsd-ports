# Ports collection makefile for:	uzbl
# Date created:				2009/12/14
# Whom:					aehlig@linta.de
#
# $FreeBSD$
#

PORTNAME=	uzbl
DISTVERSION=	0.0.0.${GITDATE}
CATEGORIES=	www
MASTER_SITES=	http://www.linta.de/distfiles/

MAINTAINER=	aehlig@linta.de
COMMENT=	Web interface tools which adhere to the unix philosophy

LIB_DEPENDS=	webkitgtk-1.0:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	socat:${PORTSDIR}/net/socat \
		dmenu:${PORTSDIR}/x11/dmenu \
		${PYTHON_PKGNAMEPREFIX}gtk>=2:${PORTSDIR}/x11-toolkits/py-gtk2

USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes

GITDATE=	2011.10.01
GITVERSION=	9576f59

WRKSRC=		${WRKDIR}/Dieterbe-uzbl-${GITVERSION}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

MAKE_JOBS_SAFE=	YES

.if !defined(NOPORTDOCS)
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

post-build:
	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" \) -exec ${RM} -f {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uzbl-core ${PREFIX}/bin
.for f in uzbl-event-manager uzbl-browser uzbl-tabbed
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
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
