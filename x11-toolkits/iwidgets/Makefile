PORTNAME=	iwidgets
PORTVERSION=	4.0.1
PORTREVISION=	2
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/incrtcl/%5BIncr%20Widgets%5D/${PORTVERSION}
DISTNAME=	iwidgets${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Iwidgets - [incr Widgets] companion to [incr Tk]
WWW=		https://sourceforge.net/projects/incrtcl/

LICENSE=	DTSTECH
LICENSE_NAME=	DTSTECH
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	auto-accept

LIB_DEPENDS=	libitk.so:x11-toolkits/itk

NO_BUILD=	yes
USES=		tk:tea
CONFIGURE_ARGS=	--with-itcl=${LOCALBASE}
SUB_LIST=	IWIDGETS=${DISTNAME}
SUB_FILES=	pkg-message
PLIST_SUB=	IWIDGETS=${DISTNAME}
MAKE_ARGS+=	INSTALL_ROOT=${STAGEDIR}

PORTDOCS=	CHANGES ChangeLog README iwidgets.ps

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/iwidgets
	${LN} -s ${DISTNAME} ${STAGEDIR}${PREFIX}/lib/iwidgets
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/iwidgets.ps ${STAGEDIR}${DOCSDIR}
.for f in CHANGES ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
