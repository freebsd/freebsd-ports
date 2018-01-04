# Created by: Ulrich Spoerlein <uspoerlein@gmail.com>
# $FreeBSD$

PORTNAME=	mdocml
PORTVERSION=	1.14.3
CATEGORIES=	textproc
MASTER_SITES=	http://mdocml.bsd.lv/snapshots/ \
		LOCAL/uqs
DISTNAME=	mandoc-${DISTVERSION}

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	mdoc macro compiler

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

EXAMPLESDIR=	${PREFIX}/share/examples/mandoc

HAS_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-configure:
	@${REINPLACE_CMD} -e '/^CFLAGS/s/-g//' -e '/^PREFIX/s/=/?=/' \
		-e 's/^INSTALL_PROGRAM.*/INSTALL_PROGRAM=${INSTALL_PROGRAM}/' \
		${WRKSRC}/Makefile.local

.include <bsd.port.mk>
