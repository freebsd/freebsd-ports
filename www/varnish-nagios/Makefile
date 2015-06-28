# Created by: anders
# $FreeBSD$

PORTNAME=	varnish-nagios
PORTVERSION=	1.1.20140519
PORTREVISION=	0
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin to check status of Varnish

BUILD_DEPENDS=	varnish4>=0:${PORTSDIR}/www/varnish4

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
CFLAGS+=	-lm

USES=		autoreconf libtool pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	varnish
GH_TAGNAME=	022fbf9

PLIST_FILES=	libexec/nagios/check_varnish

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/check_varnish ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
