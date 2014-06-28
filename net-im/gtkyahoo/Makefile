# Created by: dannyman@dannyland.org
# $FreeBSD$

PORTNAME=	gtkyahoo
PORTVERSION=	0.18.3
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yahoo Messenger Client using GTK

BROKEN=		Fails to configure
DEPRECATED=	Broken, unmaintained, unstaged, gtk12, i386 only
EXPIRATION_DATE=	2014-07-28

USE_GNOME=	gtk12
USES=		bison
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/@INSTALL@/s/$$INSTALL/${INSTALL}/; \
		s/echo aout/echo elf/' \
		${WRKSRC}/libyahoo/configure

.include <bsd.port.mk>
