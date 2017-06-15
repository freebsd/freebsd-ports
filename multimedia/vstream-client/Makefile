# Created by: Frank Mayhar <frank@exit.com>
# $FreeBSD$

PORTNAME=	vstream-client
PORTVERSION=	1.2.1.1
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client library for the Tivo vstream server

LICENSE=	GPLv2

BROKEN=		Unfetchable (google code has gone away)
DEPRECATED=	Unfetchable for more than six months (google code has gone away)
EXPIRATION_DATE=	2017-04-30

USES=		tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

PLIST_FILES=	bin/vstream-client \
		include/vstream-client.h \
		lib/libvstream-client.a

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(INSTALL) -m 755|$${BSD_INSTALL_PROGRAM}| ; \
		 s|$$(INSTALL) -m 644|$${BSD_INSTALL_DATA}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
