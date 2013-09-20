# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	pop3lite
PORTVERSION=	0.2.4a
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible, modular RFC-compliant POP3 daemon

USE_AUTOTOOLS=	libtool libltdl
USE_GNOME=	glib12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN5=		pop3lite.conf.5
MAN8=		pop3lite.8
INFO=		pop3lite-admin

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
