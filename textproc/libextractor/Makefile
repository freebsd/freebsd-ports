# New ports collection makefile for:	libextractor
# Date created:		25 May 2005
# Whom:			kevlo@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	libextractor
PORTVERSION=	0.5.0
CATEGORIES=	textproc
MASTER_SITES=	http://gnunet.org/libextractor/download/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Library for keyword extraction

USE_BZIP2=	yes
USE_GNOME=	glib20
USE_PYTHON=	yes
USE_LIBLTDL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-ltdl-install
INSTALLS_SHLIB=	yes

MAN1=		extract.1
MAN3=		libextractor.3

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/src/plugins/Makefile.in
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/src/plugins/Makefile.am

.include <bsd.port.mk>
