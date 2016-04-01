# Created by: Mark R V Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jacal
PORTVERSION=	1c4
CATEGORIES=	math
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Symbolic mathematics program written in Scheme

LICENSE=	GPLv3

RUN_DEPENDS=	scm:lang/scm \
		${LOCALBASE}/share/slib/require.scm:lang/slib

WRKSRC=		${WRKDIR}/jacal

USES=		gmake perl5 zip
NO_BUILD=	yes

INFO=		jacal

do-configure:
	cd ${WRKSRC}; \
	${FIND} . -type f -exec ${PERL} -spi -e 's|%%PREFIX%%|${PREFIX}|' {} ';'
	cd ${WRKSRC}; \
	./configure

post-install:
	${SED} -i '' -e 's|${STAGEDIR}${PREFIX}|${PREFIX}|g' ${STAGEDIR}${PREFIX}/bin/jacal

.include <bsd.port.mk>
