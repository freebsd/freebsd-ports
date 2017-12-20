# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	2.2.5
CATEGORIES=	textproc
MASTER_SITES=	https://github.com/libexpat/libexpat/releases/download/R_${PORTVERSION:S|.|_|g}/

MAINTAINER=	svysh.fbsd@gmail.com
COMMENT=	XML 1.0 parser written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		libtool pathfix tar:bz2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
