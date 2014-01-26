# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	dfm
PORTVERSION=	0.99.9
PORTREVISION=	9
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.kaisersite.de/dfm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OS/2 - like Desktop-File-Manager for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_XORG=	xpm
USE_GNOME=	imlib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--enable-imlib-icons

MYPORTDOCS=	ANNOUNCE BUGS COPYRIGHT CREDITS ChangeLog DOWNLOAD HELP.ERROR \
		NO_WARRANTY README START TESTED TODO

pre-patch:
	@${REINPLACE_CMD} -e \
		's|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	@${MKDIR}  ${STAGEDIR}${PREFIX}/share/examples/dfm
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_local ${STAGEDIR}${PREFIX}/share/examples/dfm/dfmext.sample.local
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_normal  ${STAGEDIR}${PREFIX}/share/examples/dfm/dfmext.sample.normal
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_user  ${STAGEDIR}${PREFIX}/share/examples/dfm/dfmext.sample.user
.if !defined(NOPORTDOCS)
	@${MKDIR}  ${STAGEDIR}${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file}  ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
