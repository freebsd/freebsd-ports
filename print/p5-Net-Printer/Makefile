# New ports collection makefile for:	p5-Net-Printer
# Date created:		14 August 2003
# Whom:	      		andrew@scoop.co.nz
#
# $FreeBSD$
#

PORTNAME=	Net-Printer
PORTVERSION=	0.32
CATEGORIES=	print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrew@scoop.co.nz
COMMENT=	Perl extension for direct-to-lpd printing

PERL_CONFIGURE=	yes

MAN3=		Net::Printer.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
