# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	links
PORTVERSION=	2.0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://atrey.karlin.mff.cuni.cz/~clock/twibright/links/download/ \
		http://unixpages.org/distfiles/

MAINTAINER=	demon@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-javascript --with-ssl --without-svgalib

USE_OPENSSL=	yes
USE_BZIP2=	yes

.if !defined(WITHOUT_X11)
LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff
USE_XLIB=	yes
CONFIGURE_ARGS+=	--enable-graphics --with-x
.endif

MAN1=		links.1

pre-everything::
		@${ECHO_MSG} "Define WITHOUT_X11 to disable graphics support."

post-install:
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/doc/links_cal/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
