# ex:ts=8
# Ports collection makefile for:	bk_edit
# Date created:			Dec 26, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bk_edit
PORTVERSION=	0.6.23
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.allesdurcheinander.de/nettools/bk_edit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bookmark Editor

USE_GNOME=	gtk12 libxml2
USE_BISON=	yes
USE_GETOPT_LONG=	yes
USE_REINPLACE=	yes
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
