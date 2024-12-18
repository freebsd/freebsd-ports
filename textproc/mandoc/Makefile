PORTNAME=	mandoc
PORTVERSION=	1.14.6
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://mandoc.bsd.lv/snapshots/ \
		LOCAL/uqs

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of for tools compiling mdoc and man macros
WWW=		https://mandoc.bsd.lv/

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

EXAMPLESDIR=	${PREFIX}/share/examples/mandoc

HAS_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-configure:
	@${REINPLACE_CMD} -e '/^CFLAGS/s/=/?=/' -e '/^PREFIX/s/=/?=/' \
		-e 's/^INSTALL_PROGRAM.*/INSTALL_PROGRAM=${INSTALL_PROGRAM}/' \
		-e 's|/var/www|${WWWDIR}|' \
		-e 's|^MANDIR.*|MANDIR=${PREFIX}/share/man|' \
		${WRKSRC}/Makefile.local
	${CP} ${WRKSRC}/cgi.h.example ${WRKSRC}/cgi.h

post-build:
	cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} man.cgi

post-install:
	cd ${WRKSRC} && ${MAKE} ${MAKE_ARGS} cgi-install

.include <bsd.port.mk>
