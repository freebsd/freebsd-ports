PORTNAME=	libu2f-host
PORTVERSION=	1.1.10
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=	security devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yubico Universal 2nd Factor (U2F) Host C Library

LICENSE=	LGPL21+ GPLv3+
LICENSE_COMB=	multi

BUILD_DEPENDS=	gengetopt:devel/gengetopt \
		help2man:misc/help2man
LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libjson-c.so:devel/json-c
RUN_DEPENDS=	${LOCALBASE}/etc/devd/u2f.conf:security/u2f-devd

USES=	autoreconf pkgconfig gmake libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	Yubico

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc
DOCS_CONFIGURE_ENABLE=	gtk-doc

.include <bsd.port.mk>
