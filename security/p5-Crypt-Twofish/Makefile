# New ports collection makefile for:	Crypt-Twofish
# Date created:				Wed Jan  3 16:29:03 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Crypt-Twofish
PORTVERSION=	2.12
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

RESTRICTED=	"Crypto; export-controlled"

PERL_CONFIGURE=	yes

MAN3=		Crypt::Twofish.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

SITE_PERL?=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}

PERL_MAJOR=${PERL_VER:C|^([1-9]+).*|\1|}
PERL_MINOR=${PERL_VER:C|^[1-9]+\.0*([1-9]+).*|\1|}

.if ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 8
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec
.endif # ${PERL_MAJOR} < 5 || ${PERL_MAJOR} == 5 && ${PERL_MINOR} < 8

.include <bsd.port.post.mk>
