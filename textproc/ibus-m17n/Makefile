# Created by: Nikola Lecic <nikola.lecic@anthesphoria.net>
# $FreeBSD$

PORTNAME=	ibus-m17n
PORTVERSION=	1.3.3
PORTREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	nikola.lecic@anthesphoria.net
COMMENT=	The m17n IMEngine for IBus framework

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libibus-1.0.so:textproc/ibus \
		libm17n.so:devel/m17n-lib
RUN_DEPENDS=	ibus-daemon:textproc/ibus

PROJECTHOST=	ibus

USES=		gmake pkgconfig
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/m17n|$${pkgdatadir}|g' \
		${WRKSRC}/src/m17n.xml.in*

.include <bsd.port.mk>
