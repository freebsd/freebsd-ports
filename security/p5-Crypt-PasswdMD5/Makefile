# New ports collection makefile for:	p5-Crypt-PasswdMD5
# Date created:				18 June, 2002
# Whom:					Erwin Lansing <erwin@lansing.dk>
#
# $FreeBSD$
#

PORTNAME=	Crypt-PasswdMD5
PORTVERSION=	1.2
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

USE_REINPLACE=	yes
PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::PasswdMD5.3

pre-patch:
	@${REINPLACE_CMD} -e 's|[[:cntrl:]]$$||g' ${WRKSRC}/PasswdMD5.pm

.include <bsd.port.mk>
