# New ports collection makefile for:	ipsumdump
# Date created:				12.01.2004
# Whom:					krion@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	ipsumdump
PORTVERSION=	1.34
CATEGORIES=	net
MASTER_SITES=	http://www.icir.org/kohler/ipsumdump/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Produce ASCII summary of network traffic or tcpdump(1) file

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_PERL5_BUILD=yes
USE_GMAKE=	yes

MAN1=		${PORTNAME}.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
