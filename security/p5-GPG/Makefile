# New ports collection makefile for:	p5-GPG
# Date created:				12 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	GPG
PORTVERSION=	0.06
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../../authors/id/M/MI/MILES
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@FreeBSD.org

BUILD_DEPENDS=	gpg:${PORTSDIR}/security/gnupg
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=	GPG.3

post-patch:
	@${PERL} -pi -e 's,/usr/local,${LOCALBASE},' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
