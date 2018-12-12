# Created by: Johannes Dieterich <dieterich@ogolem.org>
# $FreeBSD$

PORTNAME=	libxc
DISTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.tddft.org/programs/octopus/download/libxc/${DISTVERSION}/

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Library of exchange-correlation functionals for DFT

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fortran gmake libtool perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
