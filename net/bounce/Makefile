PORTNAME=	bounce
PORTVERSION=	1.0
PORTREVISION=	8
CATEGORIES=	net security
MASTER_SITES=	http://www.iagora.com/~espel/ \
		LOCAL/obrien
DISTNAME=	bounce
EXTRACT_SUFX=	.c

MAINTAINER=	matt@efs.org
COMMENT=	Bounce TCP connections to another machine/port

USE_RC_SUBR=	bounce
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	sbin/bounce

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/${DISTNAME} ${WRKSRC}/${DISTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
