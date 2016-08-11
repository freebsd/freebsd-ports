# Created by: chuckr
# $FreeBSD$

PORTNAME=	iwidgets
PORTVERSION=	4.0.1
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk
MASTER_SITES=	SF/incrtcl/%5BIncr%20Widgets%5D/${PORTVERSION}
DISTNAME=	iwidgets${PORTVERSION}

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	Iwidgets - [incr Widgets] companion to [incr Tk]

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

post-patch:
	${REINPLACE_CMD} -e 's,^MKINSTALLDIRS =.*,MKINSTALLDIRS=${MKDIR},' \
		-e 's,^INSTALL =.*,INSTALL=${INSTALL} -c,' \
		-e 's,^INSTALL_PROGRAM =.*,INSTALL_PROGRAM=${INSTALL_PROGRAM},' \
		-e 's,^INSTALL_DATA =.*,INSTALL_DATA=${INSTALL_DATA},' \
		-e 's,^INSTALL_SCRIPT =.*,INSTALL_SCRIPT=${INSTALL_SCRIPT},' \
		-e 's,@ITCL_VERSION@,3.3,g' ${WRKSRC}/Makefile.in

post-install:
	${RM} -f ${STAGEDIR}${PREFIX}/lib/iwidgets
	${LN} -s ${DISTNAME} ${STAGEDIR}${PREFIX}/lib/iwidgets
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/iwidgets.ps ${STAGEDIR}${DOCSDIR}
.for f in CHANGES ChangeLog README
	${INSTALL_MAN} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
