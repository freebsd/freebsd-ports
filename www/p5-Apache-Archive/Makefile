# New ports collection makefile for:	Apache::Archive
# Date created:				04 Nov 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-Archive
PORTVERSION=	0.1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module that creates a menu to allow perusal of tarball contents

BUILD_DEPENDS=	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

PERL_CONFIGURE=	yes

MAN3=		Apache::Archive.3

.include <bsd.port.mk>
