# New ports collection makefile for:	dfm
# Date created:				25 May 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	dfm
PORTVERSION=	0.99.8
CATEGORIES=	x11-fm
MASTER_SITES=	http://dfm.online.de/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_IMLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-imlib-icons

MAN1=		dfm.1x

PORTDOCS=	ANNOUNCE BUGS COPYRIGHT CREDITS ChangeLog DOWNLOAD HELP.ERROR \
		NO_WARRANTY README START TESTED TODO

pre-patch:
	@${PERL} -pi -e \
		's|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/share/examples/dfm
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_local ${PREFIX}/share/examples/dfm/dfmext.sample.local
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_normal ${PREFIX}/share/examples/dfm/dfmext.sample.normal
	${INSTALL_DATA} ${WRKSRC}/dfmext-samples/dfmext_user ${PREFIX}/share/examples/dfm/dfmext.sample.user
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/dfm
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/dfm
.endfor
.endif

.include <bsd.port.mk>
