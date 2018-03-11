# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	chemtool
PORTVERSION=	1.6.11
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draw organic molecules easily and store them

LIB_DEPENDS=	libEMF.so:graphics/libemf
RUN_DEPENDS=	transfig:print/transfig

USES=		gmake pkgconfig
USE_GNOME=	gtk20
USE_XORG=	x11
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libEMF
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--enable-emf=yes --with-localedir=${PREFIX}

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	@${REINPLACE_CMD} 's/-lstdc++//' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chemtool ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src-cht/cht ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/chemtool.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cht.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
