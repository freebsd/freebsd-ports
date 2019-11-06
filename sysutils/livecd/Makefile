# Created by: Edson Brandi <ebrandi.home@uol.com.br>
# $FreeBSD$

PORTNAME=	livecd
PORTVERSION=	1.2.4b
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.primeirospassos.org/

MAINTAINER=	ebrandi.home@uol.com.br
COMMENT=	Tool Set to create custom FreeBSD LiveCD

BROKEN=		unfetchable

RUN_DEPENDS=	cdrecord:sysutils/cdrtools

NO_BUILD=	yes
MAKE_ENV=	INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_SCRIPT="${INSTALL_SCRIPT}"

post-patch:
	@${REINPLACE_CMD} -E -e 's|/usr/local/|${PREFIX}|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
