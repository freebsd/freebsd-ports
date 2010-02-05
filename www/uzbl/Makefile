# Ports collection makefile for:	uzbl
# Date created:				2009/12/14
# Whom:					aehlig@linta.de
#
# $FreeBSD$
#

PORTNAME=	uzbl
DISTVERSION=	0.0.0.${GITDATE}
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.linta.de/distfiles/ \
		LOCAL/ehaupt

MAINTAINER=	aehlig@linta.de
COMMENT=	Web interface tools which adhere to the unix philosophy

LIB_DEPENDS=	webkit:${PORTSDIR}/www/webkit-gtk2

USE_GNOME=	gtk20
USE_LDCONFIG=	yes

GITDATE=	2010.01.05
GITVERSION=	1958b52

WRKSRC=		${WRKDIR}/Dieterbe-uzbl-${GITVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|" \
		${WRKSRC}/examples/config/uzbl/config \
		${WRKSRC}/uzbl-browser \
		${WRKSRC}/examples/data/uzbl/scripts/uzbl-event-manager

post-build:
	@${FIND} ${WRKSRC} \( -name "*.orig" -or -name "*.bak" \) -exec rm -f {} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uzbl-core ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/uzbl-browser ${PREFIX}/bin
.for f in uzbl-event-manager uzbl-cookie-daemon uzbl-tabbed
	${INSTALL_SCRIPT} ${WRKSRC}/examples/data/uzbl/scripts/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${DATADIR}/docs
	${INSTALL_DATA} ${WRKSRC}/config.h ${DATADIR}/docs
.for f in COMMUNITY CONTRIBUTING FAQ INSTALL TODO config-syntax \
		multiple-instances-management performance url-editing
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DATADIR}/docs
.endfor
.for f in AUTHORS README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/docs
.endfor
	${MKDIR} ${DATADIR}/examples/config/uzbl \
		${DATADIR}/examples/data/uzbl/forms
.for f in examples/config/uzbl/config examples/config/uzbl/cookies \
	examples/data/uzbl/bookmarks \
	examples/data/uzbl/forms/bbs.archlinux.org \
	examples/data/uzbl/style.css examples/data/uzbl/uzbl.png
		${INSTALL_DATA} ${WRKSRC}/${f} ${DATADIR}/${f}
.endfor
	(cd ${WRKSRC}/examples/data/uzbl && \
		${COPYTREE_BIN} plugins ${DATADIR}/examples/data/uzbl)
	(cd ${WRKSRC}/examples/data/uzbl && \
		${COPYTREE_BIN} scripts ${DATADIR}/examples/data/uzbl)

.include <bsd.port.mk>
