# New ports collection makefile for:	File-Scan-ClamAV
# Date created:		2006-11-24
# Whom:			Jan-Peter Koopmann <Jan-Peter.Koopmann@seceidos.de>
#
# $FreeBSD$
#

PORTNAME=	File-Scan-ClamAV
PORTVERSION=	1.8
PORTREVISION=	5
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the clamav virus scanner

BUILD_DEPENDS=	clamscan:${PORTSDIR}/security/clamav
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::Scan::ClamAV.3

.include <bsd.port.mk>
