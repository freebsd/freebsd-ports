# New ports collection makefile for:	p5-FreeBSD-Ports
# Date created:				12 September 2001
# Whom:					Tom Hukins <tom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FreeBSD-Ports
PORTVERSION=	0.04
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tom
PKGNAMEPREFIX=	p5-

MAINTAINER=	tom@FreeBSD.org
COMMENT=	Perl modules for parsing FreeBSD's Ports INDEX file

USE_BZIP2=	yes

PERL_CONFIGURE=	yes
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		FreeBSD::Ports::Port.3 \
		FreeBSD::Ports.3
.include <bsd.port.mk>
