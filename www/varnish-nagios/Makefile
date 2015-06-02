# Created by: anders
# $FreeBSD$

PORTNAME=	varnish-nagios
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin to check status of Varnish

BUILD_DEPENDS=	${LOCALBASE}/include/varnish/varnishapi.h:${PORTSDIR}/www/varnish

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes

USES=		pkgconfig

PLIST_FILES=	libexec/nagios/check_varnish

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/check_varnish ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
