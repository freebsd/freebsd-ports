# New ports collection makefile for:	httplog
# Date created:				25 November 2001
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	httplog
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache log rollover program with strftime(3) filename support

MAN8=		httplog.8

PLIST_FILES=	sbin/httplog
PORTDOCS=	ChangeLog README

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

post-patch:
	(cd ${WRKSRC} && \
	${REINPLACE_CMD} -e "s@<wait.h>@<sys/wait.h>@" httplog.c && \
	${REINPLACE_CMD} -e \
		"s@/var/lib/apache/bin/httplog@${PREFIX}/sbin/httplog@" \
	httplog.8)

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o httplog httplog.c -lz)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httplog ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/httplog.8 ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
