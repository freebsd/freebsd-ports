# ports collection makefile for:	qcl
# Date created:        23 May 2001
# Whom:                Brad Huntting <huntting@glarp.com>
#
# $FreeBSD$
#

PORTNAME=	qcl
PORTVERSION=	0.4.1
CATEGORIES=	emulators math
MASTER_SITES=	http://tph.tuwien.ac.at/~oemer/tgz/
EXTRACT_SUFX=	.tgz

MAINTAINER=	huntting@glarp.com
COMMENT=	A quantum computer simulator

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=         "Does not compile (bad C++ code)"
.endif

post-install:
	strip ${PREFIX}/bin/qcl

.include <bsd.port.post.mk>
