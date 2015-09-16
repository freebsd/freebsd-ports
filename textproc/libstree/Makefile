# Created by: clsung
# $FreeBSD$

PORTNAME=	libstree
PORTVERSION=	0.4.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.icir.org/christian/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Suffix Tree Library

USES=		gmake libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^\(SUBDIRS = src test\) docs,\1,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
