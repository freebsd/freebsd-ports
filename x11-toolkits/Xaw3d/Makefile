# Created by: asami
# $FreeBSD$

PORTNAME=	Xaw3d
PORTVERSION=	1.5E
PORTREVISION=	8
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://slackware.cs.utah.edu/pub/slackware/slackware64-13.1/source/x/xaw3d/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3-D Athena Widget set that looks like Motif

LICENSE=	MIT

WRKSRC=		${WRKDIR}/xc/lib/Xaw3d
USES=		gettext imake xorg
USE_XORG=	x11 xext xmu xt sm ice xpm
USE_LDCONFIG=	yes

SUB_FILES=	pkg-message
XAWVER=		8
SUB_LIST=	XAWVER="${XAWVER}"

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MKDIR} ${WRKSRC}/X11/Xaw3d
	@cd ${WRKSRC}/X11/Xaw3d; ${LN} -sf ../../*.h .

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXaw3d.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.XAW3D ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
