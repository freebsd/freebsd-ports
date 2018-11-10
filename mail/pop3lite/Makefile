# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	pop3lite
PORTVERSION=	0.2.4a
PORTREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flexible, modular RFC-compliant POP3 daemon

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USES=		gmake libtool
USE_GNOME=	glib12
USE_LDCONFIG=	yes

INFO=		pop3lite-admin

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pop3lite/*.so

.include <bsd.port.mk>
