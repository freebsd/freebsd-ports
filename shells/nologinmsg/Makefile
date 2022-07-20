PORTNAME=	nologinmsg
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	shells sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	freebsd-security@rikrose.net
COMMENT=	More functional native binary replacement for /sbin/nologin

USES=		uidfix

do-extract:
	@${MKDIR} ${WRKSRC}
.for i in Makefile nologinmsg.c nologinmsg.8 pathnames.h
	@${CP} ${FILESDIR}/${i} ${WRKSRC}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/nologinmsg.8 \
		${WRKSRC}/pathnames.h

pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/nologinmsgs

.include <bsd.port.mk>
