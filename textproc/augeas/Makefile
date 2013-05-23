# vim: ts=8 sw=8
# Ports collection makefile for:  textproc/augeas
# Date created:			  19 May 2010
# Whom:				  Russell Jackson <raj@csub.edu>
#
# $FreeBSD$
#

PORTNAME=	augeas
PORTVERSION=	1.0.0
#PORTREVISION=	0
CATEGORIES=	textproc
MASTER_SITES=	http://download.augeas.net/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A configuration editing tool

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
	@${REINPLACE_CMD} -e 's:%%LOCALBASE%%:${LOCALBASE}:' \
		${WRKSRC}/lenses/puppet.aug \
		${WRKSRC}/lenses/puppetfileserver.aug

.include <bsd.port.mk>
