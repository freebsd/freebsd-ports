# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	vii
PORTVERSION=	4.2
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://vii.sourceforge.net/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Execute a command repeatedly and scroll the output

LICENSE=	GPLv2

LIB_DEPENDS=	libexplain.so:devel/libexplain

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vii man/man1/vii.1.gz

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
