# ports collection makefile for:	p5-Mail-GnuPG
# Date created:				Oct 16th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$
#

PORTNAME=	Mail-GnuPG
PORTVERSION=	0.18
CATEGORIES=	mail security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to process and/or create PGP email

BUILD_DEPENDS=	p5-GnuPG-Interface>=0:${PORTSDIR}/security/p5-GnuPG-Interface \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Mail::GnuPG.3

.include <bsd.port.mk>
