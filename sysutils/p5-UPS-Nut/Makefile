# New ports collection makefile for:	sysutils/p5-UPS-Nut
# Date created:				Apr 09 2003
# Whom:					somebody who didn't run portlint
#
# $FreeBSD$
#

PORTNAME=	UPS-Nut
PORTVERSION=	0.04
CATEGORIES=	sysutils perl5
MASTER_SITES=	ftp://ftp.sedl.org/pub/mirrors/CPAN/modules/by-authors/id/K/KP/KPETERS/ \
		http://mirror.hiwaay.net/CPAN/modules/by-authors/id/K/KP/KPETERS/
PKGNAMEPREFIX=	p5-

MAINTAINER=	eric@cirr.com
COMMENT=	Perl module for accessing Network UPS Tools' upsd

PERL_CONFIGURE=	yes

MAN3=		UPS::Nut.3

pre-configure:
	${PERL} -pi -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
