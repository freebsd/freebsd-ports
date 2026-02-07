PORTNAME=	iwidgets
PORTVERSION=	4.1.1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/incrtcl/%5BIncr%20Widgets%5D/${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Iwidgets - [incr Widgets] companion to [incr Tk]
WWW=		https://sourceforge.net/projects/incrtcl/

LICENSE=	DTSTECH
LICENSE_NAME=	DTSTECH
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	auto-accept dist-mirror dist-sell pkg-mirror pkg-sell

LIB_DEPENDS=	libitk.so:x11-toolkits/itk

NO_BUILD=	yes
USES=		tk:tea
CONFIGURE_ARGS=	--with-itcl=${LOCALBASE}/lib/itcl${ITCLVER}	\
		--with-itk=${LOCALBASE}/lib/itk${ITCLVER}
ITCLVER=	3.4
SUB_LIST=	IWIDGETS=${TCL_PKG}
SUB_FILES=	pkg-message
MAKE_ARGS+=	INSTALL_ROOT=${STAGEDIR}

PORTDOCS=	CHANGES ChangeLog README iwidgets.ps

OPTIONS_DEFINE=	DOCS

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/iwidgets
	${LN} -s ${TCL_PKG} ${STAGEDIR}${PREFIX}/lib/iwidgets

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/iwidgets.ps ${STAGEDIR}${DOCSDIR}
.for f in CHANGES ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
