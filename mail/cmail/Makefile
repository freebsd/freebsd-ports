# New ports collection makefile for:	cmail
# Date created:		31 Dec 1998
# Whom:			Chip Marshall <chip@chocobo.cx>
#
# $FreeBSD$
#

PORTNAME=	cmail
PORTVERSION=	3.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.eboai.org/pub/users/chip/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	chip@chocobo.cx

USE_BZIP2=	yes

PERL_CONFIGURE=	yes

MAN1=		cmail.1

post-install:
	${INSTALL_MAN} ${WRKSRC}/cmailrc.sample ${PREFIX}/share/examples/cmailrc.sample

.include <bsd.port.mk>
