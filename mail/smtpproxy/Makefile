# New ports collection makefile for:   smtpproxy
# Date created:                15 December 2001
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	smtpproxy
PORTVERSION=	1.1.3
CATEGORIES=	mail
MASTER_SITES=	http://www.quietsche-entchen.de/download/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
MAKEFILE=	makefile

MAN1=		smtp.proxy.1

post-patch:
	@${REINPLACE_CMD} -e 's,CC =,CC ?=,; s,CFLAGS =,CFLAGS +=,; \
		s,/usr/local/sbin,${PREFIX}/libexec,; s,/usr/local,${PREFIX},' \
		${WRKSRC}/makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README rfc821.txt
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
