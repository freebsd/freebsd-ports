# Created by: Mark R V Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jacal
PORTVERSION=	1c2
CATEGORIES=	math
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Symbolic mathematics program written in Scheme

RUN_DEPENDS=	scm:${PORTSDIR}/lang/scm \
		${LOCALBASE}/share/slib/require.scm:${PORTSDIR}/lang/slib

WRKSRC=		${WRKDIR}/jacal

USES=		gmake perl5 zip
NO_BUILD=	yes

MAN1=		jacal.1
INFO=		jacal

NO_STAGE=	yes
do-configure:
	cd ${WRKSRC}; \
	${FIND} . -type f -exec ${PERL} -spi -e 's|%%PREFIX%%|${PREFIX}|' {} ';'
	cd ${WRKSRC}; \
	./configure

.include <bsd.port.mk>
