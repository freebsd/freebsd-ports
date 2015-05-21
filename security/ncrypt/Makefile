# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	ncrypt
PORTVERSION=	0.7.0
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced AES file encryption tool

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		tar:tgz

PLIST_FILES=	bin/ncrypt bin/nrm

post-patch:
	@${REINPLACE_CMD} -E 's,^(CC|CFLAGS) =,\1 \?=,g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
