# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libucl
PORTVERSION=	0.5.2
CATEGORIES=	textproc devel

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Universal configuration library parser

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool pathfix pkgconfig
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

GH_ACCOUNT=	vstakhov
GH_PROJECT=	${PORTNAME}
GH_COMMIT=	b400246

PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=	install-strip
CONFLICTS_INSTALL=	ucl

.include <bsd.port.mk>
