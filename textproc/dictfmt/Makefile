# Created by: Kimura Fuyuki <fuyuki@hadaly.org>
# $FreeBSD$

PORTNAME=	dictfmt
PORTVERSION=	1.12.1
CATEGORIES=	textproc
MASTER_SITES=	SF/dict/dictd/dictd-${PORTVERSION}
DISTNAME=	dictd-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Formats a DICT protocol dictionary database

LICENSE=	GPLv2

LIB_DEPENDS=	libmaa.so:${PORTSDIR}/devel/libmaa

USES=		gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-cflags="${CFLAGS}"
ALL_TARGET=	dictfmt
INSTALL_TARGET=	install.dictfmt
USE_AUTOTOOLS=	libtoolize

PLIST_FILES=	bin/dictfmt bin/dictfmt_index2suffix bin/dictfmt_index2word \
		bin/dictunformat man/man1/dictfmt.1.gz \
		man/man1/dictfmt_index2suffix.1.gz \
		man/man1/dictfmt_index2word.1.gz man/man1/dictunformat.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
