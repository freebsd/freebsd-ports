# Created by: Sergei Barbarash <sgt@outline.ru>
# $FreeBSD$

PORTNAME=	wmlj
PORTVERSION=	0.4.0
PORTREVISION=	8
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dockapp that monitors your friends list at LiveJournal.com

LIB_DEPENDS=	libcurl.so:ftp/curl

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12

PLIST_FILES=	bin/wmlj \
		man/man1/wmlj.1.gz

post-patch:
	@${REINPLACE_CMD} -e '/<curl\/types.h>/d' ${WRKSRC}/src/network.c

.include <bsd.port.mk>
