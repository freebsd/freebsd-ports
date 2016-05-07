# Created by: Russell Jackson <raj@csub.edu>
# $FreeBSD$

PORTNAME=	augeas
PORTVERSION=	1.4.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.augeas.net/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Configuration editing tool

LICENSE=	LGPL21

TEST_DEPENDS=	bash:shells/bash \
		gsed:textproc/gsed

GNU_CONFIGURE=	yes
USES=		autoreconf cpe gmake libtool pkgconfig readline
USE_GNOME=	libxml2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

LENSESDIR=	${PREFIX}/share/augeas/lenses

post-patch:
	@${REINPLACE_CMD} -e 's:$$(libdir)/pkgconfig:${PREFIX}/libdata/pkgconfig:' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's:/bin/bash:/usr/bin/env bash:' ${WRKSRC}/tests/*.sh
	@${REINPLACE_CMD} -e 's:sed:gsed:' ${WRKSRC}/tests/test-augtool.sh
	@${REINPLACE_CMD} -e 's:/usr/local:${LOCALBASE}:' \
		${WRKSRC}/lenses/puppet.aug \
		${WRKSRC}/lenses/puppet_auth.aug \
		${WRKSRC}/lenses/puppetfileserver.aug

.include <bsd.port.mk>
