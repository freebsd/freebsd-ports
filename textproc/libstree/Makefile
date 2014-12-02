# Created by: clsung
# $FreeBSD$

PORTNAME=	libstree
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://www.icir.org/christian/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Suffix Tree Library

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^\(SUBDIRS = src test\) docs,\1,' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
