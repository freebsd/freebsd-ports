# New ports collection makefile for:	dfm
# Date created:				25 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	dfm
PORTVERSION=	0.99.9
PORTREVISION=	2
CATEGORIES=	x11-fm
MASTER_SITES=	http://www.kaisersite.de/dfm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OS/2 - like Desktop-File-Manager for X Window System

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GNOME=	imlib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-imlib-icons

MAN1=		dfm.1x

MYPORTDOCS=	ANNOUNCE BUGS COPYRIGHT CREDITS ChangeLog DOWNLOAD HELP.ERROR \
		NO_WARRANTY README START TESTED TODO

pre-patch:
	@${REINPLACE_CMD} -e \
		's|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/share/examples/dfm
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_local ${PREFIX}/share/examples/dfm/dfmext.sample.local
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_normal ${PREFIX}/share/examples/dfm/dfmext.sample.normal
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_user ${PREFIX}/share/examples/dfm/dfmext.sample.user
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${MYPORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
