# Created by: Richard Rose <freebsd-security@rikrose.net>
# $FreeBSD$

PORTNAME=	nologinmsg
PORTVERSION=	1.0
CATEGORIES=	shells sysutils
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	freebsd-security@rikrose.net
COMMENT=	More functional native binary replacement for /sbin/nologin

MAN8=		nologinmsg.8
MANCOMPRESSED=	yes

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKSRC}
.for i in Makefile nologinmsg.c nologinmsg.8 pathnames.h
	@${CP} ${FILESDIR}/${i} ${WRKSRC}
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/nologinmsg.8 \
		${WRKSRC}/pathnames.h

pre-install:
	${MKDIR} ${PREFIX}/etc/nologinmsgs

post-install:
	${STRIP_CMD} ${PREFIX}/bin/nologinmsg

.include <bsd.port.mk>
