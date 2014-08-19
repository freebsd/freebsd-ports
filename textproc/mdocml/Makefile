# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	mdocml
PORTVERSION=	1.13.1
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	uqs

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	mdoc macro compiler

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

EXAMPLESDIR_REL=share/examples/mandoc

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e '/^CFLAGS/s/-g//' -e '/^PREFIX/s/=/?=/' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
