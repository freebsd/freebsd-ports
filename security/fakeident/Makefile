PORTNAME=	fakeident
PORTVERSION=	2.7
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty
EXTRACT_ONLY=	# empty

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Tool that replies with a standard answer to incoming identd requests

LICENSE=	GPLv2+

PLIST_FILES=	sbin/identd

USE_RC_SUBR=	fakeidentd

do-build:
	@${MKDIR} ${WRKSRC} && ${CP} ${FILESDIR}/identd.c ${WRKSRC}
	cd ${WRKSRC} && ${SH} identd.c CC=${CC} ${CFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/identd ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
