# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	vii
PORTVERSION=	4.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://vii.sourceforge.net/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Execute a command repeatedly and scroll the output

LICENSE=	GPLv2

LIB_DEPENDS=	explain:${PORTSDIR}/devel/libexplain

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/vii
MAN1=		vii.1

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
