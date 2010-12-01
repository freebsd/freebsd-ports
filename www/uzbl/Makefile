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

LIB_DEPENDS=	webkit:${PORTSDIR}/www/webkit-gtk2
RUN_DEPENDS=	socat:${PORTSDIR}/net/socat

USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_GMAKE=	yes

GITDATE=	2010.11.25
GITVERSION=	5180049

WRKSRC=		${WRKDIR}/Dieterbe-uzbl-${GITVERSION}

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS README COMMUNITY CONTRIBUTING FAQ INSTALL TODO config-syntax \
		multiple-instances-management performance url-editing config.h vim README.cookies
.endif

.if !defined(NOPORTDATA)
PORTDATA=	examples
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" \
		${WRKSRC}/examples/config/config \
		${WRKSRC}/src/uzbl-browser \
		${WRKSRC}/examples/data/scripts/uzbl-event-manager
	@${REINPLACE_CMD} -e "s|share/uzbl|${DATADIR_REL}|" \
		${WRKSRC}/examples/config/config \
		${WRKSRC}/src/uzbl-browser \
		${WRKSRC}/examples/data/scripts/uzbl-event-manager
	@${REINPLACE_CMD} -e "s|/usr/share/uzbl|${DATADIR}|" \
		${WRKSRC}/examples/data/scripts/uzbl-tabbed

post-build:
	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" \) -exec ${RM} -f {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uzbl-core ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/uzbl-cookie-manager ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/uzbl-browser ${PREFIX}/bin
.for f in uzbl-event-manager uzbl-cookie-daemon uzbl-tabbed
	${INSTALL_SCRIPT} ${WRKSRC}/examples/data/scripts/${f} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/src/config.h ${DOCSDIR}
.for f in COMMUNITY CONTRIBUTING FAQ INSTALL TODO config-syntax \
		multiple-instances-management performance url-editing README.cookies
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
	data/style.css data/uzbl.png
		${INSTALL_DATA} ${WRKSRC}/examples/${f} ${DATADIR}/examples/${f}
.endfor
	${INSTALL_DATA} ${WRKSRC}/examples/config/config ${DATADIR}/examples/config/config
	(cd ${WRKSRC}/examples/data && \
		${COPYTREE_BIN} plugins ${DATADIR}/examples/data/)
	(cd ${WRKSRC}/examples/data && \
		${COPYTREE_BIN} scripts ${DATADIR}/examples/data/)
.endif

.include <bsd.port.mk>
