# Ports collection makefile for: sms
# Date created:		23 dec 2001
# Whom: 		Michal Pasternak <doc@lublin.t1.pl>
#
# $FreeBSD$
#

PORTNAME=	sms
PORTVERSION=	1.8.9h
CATEGORIES=	misc
MASTER_SITES=	http://www.ceti.pl/~miki/komputery/download/sms/
PKGNAMEPREFIX=	pl-

MAINTAINER=	doc@lublin.t1.pl

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

WRKSRC=	${WRKDIR}/sms
USE_GMAKE=	yes
MAKE_ARGS=	CXX="${CXX}"
.if defined(NOPORTDOCS)
MAKE_ARGS+=	NOPORTDOCS=1
.endif

post-install:
	     ${STRIP_CMD} ${PREFIX}/bin/sms

.include <bsd.port.mk>
