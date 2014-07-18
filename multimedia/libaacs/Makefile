# Created by: kamikaze@bsdforen.de
# $FreeBSD$

PORTNAME=	libaacs
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	ftp://ftp.videolan.org/pub/videolan/${PORTNAME}/${PORTVERSION}/ \
		http://blu.opsec.eu/

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Advanced Access Content System implementation

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/bin/flex:${PORTSDIR}/textproc/flex
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-debug
CONFIGURE_ENV=	LEX="${LOCALBASE}/bin/flex"
INSTALL_TARGET=	install-strip
USES=		bison gettext iconv libtool pathfix tar:bzip2
USE_LDCONFIG=	yes

.include <bsd.port.mk>
