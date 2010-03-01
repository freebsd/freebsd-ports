# Ports collection makefile for:	uzbl
# Date created:				2009/12/14
# Whom:					aehlig@linta.de
#
# $FreeBSD$
#

PORTNAME=	uzbl
DISTVERSION=	0.0.0.${GITDATE}
CATEGORIES=	www
MASTER_SITES=	http://www.linta.de/distfiles/ \
		LOCAL/ehaupt

MAINTAINER=	aehlig@linta.de
COMMENT=	Web interface tools which adhere to the unix philosophy

LIB_DEPENDS=	webkit:${PORTSDIR}/www/webkit-gtk2

USE_GNOME=	gtk20
USE_LDCONFIG=	yes
USE_GMAKE=	yes

GITDATE=	2010.02.02
GITVERSION=	f8d6c93

WRKSRC=		${WRKDIR}/Dieterbe-uzbl-${GITVERSION}

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS README COMMUNITY CONTRIBUTING FAQ INSTALL TODO config-syntax \
		multiple-instances-management performance url-editing config.h
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
		${WRKSRC}/examples/data/scripts/uzbl-event-manager

post-build:
	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" \) -exec ${RM} -f {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uzbl-core ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/uzbl-browser ${PREFIX}/bin
.for f in uzbl-event-manager uzbl-cookie-daemon uzbl-tabbed
	${INSTALL_SCRIPT} ${WRKSRC}/examples/data/scripts/${f} ${PREFIX}/bin
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
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}/examples/data/forms ${DATADIR}/examples/config
.for f in config/cookies \
	data/bookmarks \
	data/forms/bbs.archlinux.org \
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
