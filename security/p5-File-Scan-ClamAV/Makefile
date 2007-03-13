# New ports collection makefile for:	File-Scan-ClamAV
# Date created:		2006-11-24
# Whom:			Jan-Peter Koopmann <Jan-Peter.Koopmann@seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	File-Scan-ClamAV
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	File
PKGNAMEPREFIX=	p5-

MAINTAINER=	j.koopmann@seceidos.de
COMMENT=	Perl extension for the clamav virus scanner

BUILD_DEPENDS=	clamscan:${PORTSDIR}/security/clamav
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Scan::ClamAV.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6.x or later. Install lang/perl5 and try again
.endif

.include <bsd.port.post.mk>
