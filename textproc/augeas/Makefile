# Created by: Russell Jackson <raj@csub.edu>
# $FreeBSD$

PORTNAME=	augeas
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://download.augeas.net/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Configuration editing tool

LICENSE=	LGPL21

TEST_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gsed:${PORTSDIR}/textproc/gsed

USE_GNOME=	libxml2
USES=		gmake libtool pkgconfig readline
USE_AUTOTOOLS=	autoconf aclocal autoheader automake libtoolize:env
ACLOCAL_ARGS=	-I . -I gnulib/m4 -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

LENSESDIR=	${PREFIX}/share/augeas/lenses

post-patch:
	@${REINPLACE_CMD} -e 's:$$(libdir)/pkgconfig:${PREFIX}/libdata/pkgconfig:' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's:/bin/bash:/usr/bin/env bash:' ${WRKSRC}/tests/*.sh
	@${REINPLACE_CMD} -e 's:sed:gsed:' ${WRKSRC}/tests/test-augtool.sh
	@${REINPLACE_CMD} -e 's:%%LOCALBASE%%:${LOCALBASE}:' \
		${WRKSRC}/lenses/puppet.aug \
		${WRKSRC}/lenses/puppetfileserver.aug

.include <bsd.port.mk>
