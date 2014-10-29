# Created by: anders
# $FreeBSD$

PORTNAME=	varnish-nagios
DISTVERSION=	1.1
CATEGORIES=	www
MASTER_SITES=	http://repo.varnish-cache.org/source/ \
		http://anders.fupp.net/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin to check status of Varnish

BUILD_DEPENDS=	${LOCALBASE}/include/varnish/varnishapi.h:${PORTSDIR}/www/varnish

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes

USES=		pkgconfig

PLIST_DIRSTRY=	libexec/nagios
PLIST_FILES=	libexec/nagios/check_varnish

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_varnish ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
