# New ports collection makefile for:   tcpstat
# Date created:        29 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	tcpstat
PORTVERSION=	1.5
CATEGORIES=	net
MASTER_SITES=	http://www.frenchfries.net/paul/tcpstat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to report various network statistics

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		tcpstat.1 tcpprof.1
DOCS=		AUTHORS ChangeLog LICENSE README doc/Tips_and_Tricks.txt 

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
