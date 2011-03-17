# ex:ts=8
# Ports collection makefile for:	bk_edit
# Date created:			Dec 26, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bk_edit
PORTVERSION=	0.6.23
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	http://www.allesdurcheinander.de/nettools/bk_edit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bookmark Editor

BROKEN=		Broken with gcc 4.2
DEPRECATED=	does not compile on FreeBSD 7.x and newer
EXPIRATION_DATE=2011-04-17

USE_GNOME=	gtk12 libxml2
USE_BISON=	build
HAS_CONFIGURE=	yes
MAKE_ENV=	LD="${CC}" LDFLAGS="${LDFLAGS}"

post-patch:
	@${FIND} ${WRKSRC} -name "*Makefile*" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC .*=|CC ?=|g ; \
		 s|^LD .*=|LD ?=|g ; \
		 s|^CFLAGS .*=|CFLAGS +=|g ; \
		 s|^LDFLAGS .*=|LDFLAGS +=|g ; \
		 s| make| $$(MAKE)|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/bkedit ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/bkedit
	${INSTALL_DATA} ${WRKSRC}/src/plugins/*.so ${PREFIX}/lib/bkedit

.include <bsd.port.mk>
