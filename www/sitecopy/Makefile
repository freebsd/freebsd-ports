# New ports collection makefile for:	sitecopy
# Date created:		15 January 1999
# Whom:			nik
#
# $FreeBSD$
#

PORTNAME=	sitecopy
PORTVERSION=	0.11.4
CATEGORIES=	www
MASTER_SITES=	http://www.lyra.org/sitecopy/

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext \
		xml.5:${PORTSDIR}/textproc/libxml
BUILD_DEPENDS=	${LOCALBASE}/bin/neon-config:${PORTSDIR}/www/neon
RUN_DEPENDS=	${LOCALBASE}/bin/neon-config:${PORTSDIR}/www/neon

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS=	--enable-libxml
USE_GMAKE=	yes

MAN1=		sitecopy.1

.include <bsd.port.mk>
