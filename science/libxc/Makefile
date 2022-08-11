PORTNAME=	libxc
DISTVERSION=	5.2.3
CATEGORIES=	science
MASTER_SITES=	https://www.tddft.org/programs/${PORTNAME}/down/${DISTVERSION}/

MAINTAINER=	jmd@FreeBSD.org
COMMENT=	Library of exchange-correlation functionals for DFT

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fortran gmake libtool perl5
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
