# New ports collection makefile for:	p11-kit
# Date created:				2011-07-24
# Whom:				Roman Bogorodskiy <novel@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p11-kit
PORTVERSION=	0.13
CATEGORIES=	security devel
MASTER_SITES=	http://p11-glue.freedesktop.org/releases/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Library for loading and enumerating of PKCS\#11 modules

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtk-doc --disable-nls --enable-debug=no
MAKE_ENV=	exampledir=${EXAMPLESDIR}

USE_AUTOTOOLS=	libtool
USE_GNOME=	ltverhack gnomehack
USE_LDCONFIG=	yes

pre-configure:
	@${REINPLACE_CMD} -e \
	's|exampledir = $$(p11_system_config)|exampledir = ${EXAMPLESDIR}|' \
	${WRKSRC}/${PORTNAME}/Makefile.in

.include <bsd.port.mk>
