# ex:ts=8
# New ports collection makefile for:	sloccount
# Date created:			May 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sloccount
PORTVERSION=	2.09
CATEGORIES=	misc
MASTER_SITES=	http://www.dwheeler.com/sloccount/

MAINTAINER=	ports@FreeBSD.org

MAKEFILE=	makefile
INSTALL_TARGET=	install_programs install_man

MAN1=		sloccount.1

post-install:
.for file in lexcount1 c_count java_count php_count
	@strip ${PREFIX}/bin/${file}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README TODO sloccount.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
