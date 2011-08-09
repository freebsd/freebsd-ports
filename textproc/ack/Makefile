# New ports collection makefile for:	ack
# Date created:		2011-08-08
# Whom:			Steven Kreuzer <skreuzer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ack
PORTVERSION=	1.94
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/P/PE/PETDANCE

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Grep-like tool optimized for working with source code

BUILD_DEPENDS=	p5-File-Next>=1.06:${PORTSDIR}/sysutils/p5-File-Next
RUN_DEPENDS=	p5-File-BaseDir>=0.03:${PORTSDIR}/devel/p5-File-BaseDir \
		p5-Term-ANSIColor>=3.00:${PORTSDIR}/devel/p5-Term-ANSIColor \
		p5-Getopt-Long>=2.38:${PORTSDIR}/devel/p5-Getopt-Long

PERL_CONFIGURE=	yes

MAN1=	ack.1

.include <bsd.port.mk>
