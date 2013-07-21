# Created by: Russell Jackson <raj@csub.edu>
# $FreeBSD$

PORTNAME=	augeas
PORTVERSION=	1.1.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.augeas.net/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A configuration editing tool

TEST_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gsed:${PORTSDIR}/textproc/gsed

USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_AUTOTOOLS=	autoconf aclocal autoheader automake libtool
ACLOCAL_ARGS=	-I . -I gnulib/m4 -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes

MAN1=		augparse.1 augtool.1
MANCOMPRESSED=	no

LENSESDIR=	${PREFIX}/share/augeas/lenses

post-patch:
	@${REINPLACE_CMD} -e 's:$$(libdir)/pkgconfig:${PREFIX}/libdata/pkgconfig:' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's:/bin/bash:/usr/bin/env bash:' ${WRKSRC}/tests/*.sh
	@${REINPLACE_CMD} -e 's:sed:gsed:' ${WRKSRC}/tests/test-augtool.sh
	@${REINPLACE_CMD} -e 's:%%LOCALBASE%%:${LOCALBASE}:' \
		${WRKSRC}/lenses/puppet.aug \
		${WRKSRC}/lenses/puppetfileserver.aug

.include <bsd.port.mk>
