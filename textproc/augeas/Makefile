# vim: ts=8 sw=8
# Ports collection makefile for:  textproc/augeas
# Date created:			  19 May 2010
# Whom:				  Russell Jackson <raj@csub.edu>
#
# $FreeBSD$
#

PORTNAME=	augeas
PORTVERSION=	0.10.0
CATEGORIES=	textproc
MASTER_SITES=	http://augeas.net/download/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A configuration editing tool

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig libxml2
USE_AUTOTOOLS=	autoconf aclocal autoheader automake libtool
ACLOCAL_ARGS=	-I . -I gnulib/m4 -I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes

TEST_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		gsed:${PORTSDIR}/textproc/gsed

MAN1=		augparse.1 augtool.1
MANCOMPRESSED=	no

LENSESDIR=	${PREFIX}/share/augeas/lenses

post-patch:
	@${REINPLACE_CMD} -e 's:$$(libdir)/pkgconfig:${PREFIX}/libdata/pkgconfig:' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's:/bin/bash:/usr/bin/env bash:' ${WRKSRC}/tests/*.sh
	@${REINPLACE_CMD} -e 's:sed:gsed:' ${WRKSRC}/tests/test-augtool.sh

post-install:
	${MKDIR} ${LENSESDIR}/tests
	${INSTALL_DATA} ${FILESDIR}/rcconf.aug ${LENSESDIR}/rcconf.aug
	${INSTALL_DATA} ${FILESDIR}/test_rcconf.aug ${LENSESDIR}/tests/rcconf.aug

test: install
	@cd ${WRKSRC}/tests && make check

.include <bsd.port.mk>
