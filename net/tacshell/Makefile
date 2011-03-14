# New ports collection makefile for:	tacshell
# Date created:				13.06.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	tacshell
PORTVERSION=	0.91
CATEGORIES=	net
MASTER_SITES=	http://www.rezrov.net/software/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shell authentication for TACACS+ protocol

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

GNU_CONFIGURE=	yes

PORTDOCS=	README WHATSNEW ChangeLog
PLIST_FILES=	bin/tacshell etc/tacshell.conf.sample

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
