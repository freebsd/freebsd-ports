# ex:ts=8
# Ports collection makefile for:	py-rrdtool
# Date created:			May 31, 2002
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	rrdtool
PORTVERSION=	0.1
CATEGORIES=	net python
MASTER_SITES=	http://projects.gasperino.org/projects/PyRRDtool/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyRRDtool-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python C extension module to access RRDtool files

LIB_DEPENDS=	rrd:${PORTSDIR}/net/rrdtool

USE_PYTHON=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/PyRRDtool/src

.include <bsd.port.pre.mk>

post-patch:
.if ${PYTHON_REL} >= 230
	@${REINPLACE_CMD} -e 's,@DEFS@,,g' ${WRKSRC}/Makefile.pre.in
.endif
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/Setup.in

do-configure:
	@(cd ${WRKSRC} ; ${MAKE} -f Makefile.pre.in boot)

.include <bsd.port.post.mk>
