# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	sigrok-cli
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	science cad
MASTER_SITES=	http://sigrok.org/download/source/sigrok-cli/

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, CLI client

LICENSE=	GPLv3

LIB_DEPENDS=	libserialport.so:devel/libserialport \
		libsigrok.so:devel/libsigrok \
		libsigrokdecode.so:devel/libsigrokdecode

PLIST_FILES=	bin/sigrok-cli man/man1/sigrok-cli.1.gz

GNU_CONFIGURE=	yes
USES=		gmake pathfix libtool pkgconfig
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
