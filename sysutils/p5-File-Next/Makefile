# New ports collection makefile for:    p5-File-Next
# Date created:				2006/09/08
# Whom:	      				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	File-Next
PORTVERSION=	1.00
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	File-finding iterator

BUILD_DEPENDS=	p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools

PERL_CONFIGURE=	yes

MAN3=	File::Next.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=		requires perl 5.6.x or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
