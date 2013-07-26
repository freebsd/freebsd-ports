# Created by: ijliao
# $FreeBSD$

PORTNAME=	cssed
PORTVERSION=	0.4.0
PORTREVISION=	7
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application to help CSS style sheets creation and maintenance

USES=        pathfix
USE_GNOME=	gtk20 libxml2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgmodule-2.0
CONFIGURE_ARGS=	--with-plugin-headers

MAN1=		cssed.1

post-patch:
.for file in scintilla/gtk/ScintillaGTK.cxx
	@cd ${WRKSRC} && ${MV} ${file} ${file}.pre_tr \
		&& ${TR} -d '\r' < ${file}.pre_tr > ${file}
.endfor
.for file in scintilla/gtk/Makefile.in src/Makefile.in
	@${REINPLACE_CMD} -e 's|gcc|@CC@|g ; \
		 s|g++|@CXX@|g' ${WRKSRC}/src/Makefile.in
.endfor

.include <bsd.port.mk>
