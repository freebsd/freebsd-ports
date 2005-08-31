# New ports collection makefile for:	p5-Chess-PGN-Parse
# Date created: 			23 July 2005
# Whom: 				Aaron Dalton <aaron@daltons.ca>
#
# $FreeBSD$
#

PORTNAME=	Chess-PGN-Parse
PORTVERSION=	0.18
CATEGORIES=	textproc games perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/G/GM/GMAX
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@daltons.ca
COMMENT=	Reads and parses PGN (Portable Game Notation) Chess files

PERL_CONFIGURE=	yes

MAN3=		Chess::PGN::Parse.3

.include <bsd.port.pre.mk>

.if (${PERL_LEVEL} < 500600)
BROKEN=	"Require perl 5.6 or high"
.endif

.include <bsd.port.post.mk>
