# New ports collection makefile for:	RADIUS::UserFile
# Date created:				30 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		RADIUS-UserFile
PORTVERSION=		1.01
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	RADIUS
PKGNAMEPREFIX=		p5-

MAINTAINER=		svenasse@polaris.ca

BUILD_DEPENDS=		${SITE_PERL}/Tie/IxHash.pm:${PORTSDIR}/devel/p5-Tie-IxHash
RUN_DEPENDS=		${BUILD_DEPENDS}

SITE_PERL=		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

PERL_CONFIGURE=		yes

MAN3=			RADIUS::UserFile.3
MANPREFIX=		${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
