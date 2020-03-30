# Created by: Mark R V Murray <markm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jacal
PORTVERSION=	1c7
CATEGORIES=	math
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Symbolic mathematics program written in Scheme

LICENSE=	GPLv3

RUN_DEPENDS=	scm:lang/scm \
		${LOCALBASE}/share/slib/require.scm:lang/slib

USES=		gmake makeinfo zip

HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

INFO=		jacal

post-patch:
	${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' {} \;
	${CHMOD} +x ${WRKSRC}/configure

post-install:
	${SED} -i '' -e 's|${STAGEDIR}${PREFIX}|${PREFIX}|g' ${STAGEDIR}${PREFIX}/bin/jacal

.include <bsd.port.mk>
