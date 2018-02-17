# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libaacs
DISTVERSION=	0.9.0
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced Access Content System implementation

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:textproc/flex
LIB_DEPENDS=	libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error

USES=		bison gettext iconv libtool pathfix tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LEX="${LOCALBASE}/bin/flex"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include "${.CURDIR}/../libbluray/Makefile.include"

.include <bsd.port.mk>
