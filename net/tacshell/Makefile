# New ports collection makefile for:	tacshell
# Date created:				13.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	tacshell
PORTVERSION=	0.9
CATEGORIES=	net
MASTER_SITES=	http://www.rezrov.net/software/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Shell authentication for TACACS+ protocol

USE_SIZE=	yes
GNU_CONFIGURE=	yes

post-install:
.for i in ${PORTNAME}
	${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README WHATSNEW ChangeLog
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
