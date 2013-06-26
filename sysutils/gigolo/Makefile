# Created by: nemysis <nemysis@gmx.ch>
# $FreeBSD$

PORTNAME=	gigolo
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://files.uvena.de/gigolo/ \
		http://www.uvena.de/gigolo/:icons
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX} \
		network.png:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Frontend to easily manage filesystem connections

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_BZIP2=	yes
USES=		fuse
USE_GNOME=	gtk20 gvfs
USE_XORG=	x11
USE_PYTHON=	yes

MAN1=		gigolo.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	Does not compile

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|COPYING ||' ${WRKSRC}/wscript

.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e 's|bld.install_files|#bld.install_files|' ${WRKSRC}/wscript
.endif

.if ! ${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e "s|= 'po'|= ''|" ${WRKSRC}/wscript
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf configure --mandir=${MANPREFIX}/man

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install
	${INSTALL_DATA} ${_DISTDIR}/network.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
