# Ports collection makefile for:  cryptcat
# Date created:			  20 Dec 2000
# Whom:				  Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	cryptcat
PORTVERSION=	0.0
CATEGORIES=	net
MASTER_SITES=	http://farm9.com/content/Free_Tools/
DISTNAME=	cryptcat_linux
EXTRACT_SUFX=	.tar

MAINTAINER=	roman@xpert.com

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=	freebsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptcat ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cryptcat \
		&& ${CHMOD} 755 ${PREFIX}/share/doc/cryptcat
	${INSTALL_DATA} ${WRKSRC}/README.cryptcat ${PREFIX}/share/doc/cryptcat
.endif

.include <bsd.port.mk>
