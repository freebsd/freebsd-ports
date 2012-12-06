# Created by: nemysis@gmx.ch
# $FreeBSD$

PORTNAME=	gigolo
PORTVERSION=	0.4.1
CATEGORIES=	sysutils
MASTER_SITES=	http://files.uvena.de/gigolo/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Frontend to easily manage filesystem connections

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo

USE_BZIP2=	yes
USE_GNOME=	gtk20 gvfs
USE_XORG=	x11
USE_PYTHON=	yes
USE_GETTEXT=	yes

MAN1=		gigolo.1

PORTDOCS=	AUTHORS ChangeLog NEWS README TODO COPYING

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf configure --mandir=${PREFIX}/man

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf build

do-install:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./waf install

.include <bsd.port.mk>
