# Created by: Frank Mayhar <frank@exit.com>
# $FreeBSD$

PORTNAME=	vstream-client
PORTVERSION=	1.2.1.1
CATEGORIES=	multimedia
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client library for the Tivo vstream server

LICENSE=	GPLv2

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/vstream-client \
		include/vstream-client.h \
		lib/libvstream-client.a

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$(INSTALL) -m 755|$${BSD_INSTALL_PROGRAM}| ; \
		 s|$$(INSTALL) -m 644|$${BSD_INSTALL_DATA}|' ${WRKSRC}/Makefile

.include <bsd.port.mk>
