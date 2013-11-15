# Created by: anders
# $FreeBSD$

PORTNAME=	httplog
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache log rollover program with strftime(3) filename support

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
PORTDOCS=	ChangeLog README

post-patch:
	(cd ${WRKSRC} && \
	${REINPLACE_CMD} -e "s@<wait.h>@<sys/wait.h>@" httplog.c && \
	${REINPLACE_CMD} -e \
		"s@/var/lib/apache/bin/httplog@${PREFIX}/sbin/httplog@" \
	httplog.8)

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o httplog httplog.c -lz)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httplog ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/httplog.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
