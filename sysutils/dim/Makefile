# New ports collection makefile for:	dim
# Date created:			Apr 13, 2001
# Whom:				Mark Pulford <mark@kyne.com.au>
#
# $FreeBSD$
#

PORTNAME=	dim
PORTVERSION=	1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.theory.org/~matt/dim/
DISTNAME=	dim
EXTRACT_SUFX=	.tar

MAINTAINER=	markp@FreeBSD.org

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

pre-patch:
	@${PERL} -pi -e "s|^#!.+|#!${PERL}|" ${WRKSRC}/dim.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dim.pl ${PREFIX}/bin/dim

.include <bsd.port.mk>
