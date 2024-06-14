PORTNAME=	jacal
DISTVERSION=	1c8
PORTREVISION=	2
CATEGORIES=	math
MASTER_SITES=	http://groups.csail.mit.edu/mac/ftpdir/scm/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Symbolic mathematics program written in Scheme
WWW=		https://people.csail.mit.edu/jaffer/JACAL

LICENSE=	GPLv3

RUN_DEPENDS=	scm:lang/scm \
		${LOCALBASE}/share/slib/require.scm:lang/slib

USES=		gmake zip

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--mandir=${PREFIX}/share/man

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_BUILD=	yes

OPTIONS_DEFINE=	INFO
OPTIONS_DEFAULT=	INFO

INFO_USES=		makeinfo
INFO_INFO=		jacal

post-patch:
	${FIND} ${WRKSRC} -type f -exec ${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' {} \;
	${CHMOD} +x ${WRKSRC}/configure

post-patch-INFO-off:
	${REINPLACE_CMD} -e '/^install:/s|install-infoz||g' \
		${WRKSRC}/Makefile

post-install:
	${SED} -i '' -e 's|${STAGEDIR}${PREFIX}|${PREFIX}|g' ${STAGEDIR}${PREFIX}/bin/jacal

.include <bsd.port.mk>
