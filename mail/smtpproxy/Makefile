# New ports collection makefile for:   smtpproxy
# Date created:                15 December 2001
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	smtpproxy
PORTVERSION=	1.3.3
CATEGORIES=	mail
MASTER_SITES=	http://quietsche-entchen.de/cgi-bin/wiki.cgi/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SMTP proxy server

MAKEFILE=	makefile
DISABLE_SIZE=	yes

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAN1=		smtp.proxy.1
PLIST_FILES=	libexec/smtp.proxy
PORTDOCS=	README rfc821.txt

post-patch:
	@${REINPLACE_CMD} -e 's,<wait.h>,<sys/wait.h>,' ${WRKSRC}/acp.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
