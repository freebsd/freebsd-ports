# New ports collection makefile for:	flood
# Date created:		8 Jan 2003
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flood
PORTVERSION=	0.20030108
CATEGORIES=	www
MASTER_SITES=	http://www.apache.org/dist/httpd/flood/
DISTNAME=	${PORTNAME}-20030108

MAINTAINER=	kuriyama@FreeBSD.org

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2 \
		iconv.3:${PORTSDIR}/converters/libiconv \
		apr.0:${PORTSDIR}/devel/apr

USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--disable-shared
CONFIGURE_ENV=	LDFLAGS="-L${PREFIX}/lib"
USE_GMAKE=	yes

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_SCRIPT} ${WRKSRC}/examples/analyze-* ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/r* ${EXAMPLESDIR}

.include <bsd.port.mk>
