# New ports collection makefile for:	p5-Crypt-HCE_SHA
# Date created:				October 8th 2001
# Whom:	      				Gregory Neil Shapiro <gshapiro@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-HCE_SHA
PORTVERSION=	0.60
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
RUN_DEPENDS=	${BUILD_DEPENDS}

RESTRICTED=	"Crypto; export-controlled"

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Crypt::HCE_SHA.3

.include <bsd.port.mk>
