# ex:ts=8
# Ports collection makefile for:  ltrace
# Date created:			  Mon Oct 15, 2001
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	ltrace
PORTVERSION=	0.3.6
CATEGORIES=	sysutils
MASTER_SITES=	http://utopia.knoware.nl/users/driehuis/
DISTNAME=	${PORTNAME}-${PORTVERSION}-fbsd

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=		ltrace.1

post-patch:
	${REINPLACE_CMD} \
		-e 's|"/etc/ltrace.conf"|"${PREFIX}/etc/ltrace.conf"|g' \
		${WRKSRC}/ltrace.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ltrace ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/ltrace.conf ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/ltrace.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
