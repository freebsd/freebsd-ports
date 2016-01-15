# Created by: Dean Hollister <dean@odyssey.apana.org.au>
# $FreeBSD$

PORTNAME=	fakeident
PORTVERSION=	1.7
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=      # empty
EXTRACT_ONLY=   # empty

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	Tool that replies with a standard answer to incoming identd requests

LICENSE=	GPLv2+

PLIST_FILES=	sbin/identd
USE_RC_SUBR=	fakeidentd

do-build:
	@${MKDIR} ${WRKSRC}
	${CC} ${CFLAGS} -o ${WRKSRC}/identd ${FILESDIR}/identd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/identd ${STAGEDIR}${PREFIX}/sbin

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/identd

.include <bsd.port.mk>
