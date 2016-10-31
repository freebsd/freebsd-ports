# Created by: anders
# $FreeBSD$

PORTNAME=	varnish-nagios
PORTVERSION=	1.1.20151214
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nagios plugin to check status of Varnish

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	sudo:security/sudo

GNU_CONFIGURE=	yes
CFLAGS+=	-lm

USES=		autoreconf libtool pkgconfig varnish

USE_GITHUB=	yes
GH_ACCOUNT=	varnish
GH_TAGNAME=	258c486

PLIST_FILES=	libexec/nagios/check_varnish

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/nagios
	${INSTALL_PROGRAM} ${WRKSRC}/check_varnish ${STAGEDIR}${PREFIX}/libexec/nagios

.include <bsd.port.mk>
