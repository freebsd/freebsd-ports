# New ports collection makefile for:   p5-Unix-Mknod
# Date created:                        Wed Jun 15 12:44:11 CDT 2005
# Whom:                                        Jim Pirzyk pirzyk@freebsd.org
#
# $FreeBSD$
#

PORTNAME=      Unix-Mknod
PORTVERSION=   0.02
CATEGORIES=    sysutils perl5
MASTER_SITES=  ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=    Unix
PKGNAMEPREFIX= p5-

MAINTAINER=    pirzyk@FreeBSD.org
COMMENT=       Perl5 module to create special files

PERL_CONFIGURE=        yes

MAN3=          Unix::Mknod.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=         Port requires perl 5.6.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
