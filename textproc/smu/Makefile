# Created by: Dennis Herrmann <dhn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smu
PORTVERSION=	1.4
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Simple interpreter for a simplified markdown dialect

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	Gottox

PLIST_FILES=	bin/smu man/man1/smu.1.gz

USES=		uidfix
MAKEFILE=	/usr/share/mk/bsd.prog.mk
MAKE_ENV=	PROG="${PORTNAME}" \
		BINDIR="${PREFIX}/bin" \
		MANDIR="${MANPREFIX}/man/man"
CFLAGS+=	-DVERSION=${PORTVERSION}

.include <bsd.port.mk>
