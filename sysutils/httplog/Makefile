# New ports collection makefile for:	httplog
# Date created:				25 November 2001
# Whom:					anders
#
# $FreeBSD$
#

PORTNAME=	httplog
PORTVERSION=	2.1
CATEGORIES=	sysutils www
MASTER_SITES=	http://nutbar.chemlab.org/downloads/programs/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org

MAN8=	httplog.8

DOCS=	ChangeLog README

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

post-patch:
	(cd ${WRKSRC} && \
	${PERL} -pi -e "s@<wait.h>@<sys/wait.h>@" httplog.c && \
	${PERL} -pi -e \
		"s@/var/lib/apache/bin/httplog@${PREFIX}/sbin/httplog@" \
	httplog.8)

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -o httplog httplog.c -lz)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/httplog ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/httplog.8 ${PREFIX}/man/man8/
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
