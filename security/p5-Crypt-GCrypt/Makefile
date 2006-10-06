# New ports collection makefile for:	p5-Crypt-GCrypt
# Date created:		2006-09-28
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-GCrypt
PORTVERSION=	1.15
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Perl interface to the GNU Cryptographic library

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	GCRYPTLIBPATH=${LOCALBASE}/lib \
		GCRYPTINCPATH=${LOCALBASE}/include
USE_GCC=	3.2+

MAN3=		Crypt::GCrypt.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^our (\W\w+);/use vars q($$1);/o;' \
	    -e 's/^our\s+(\W\w+)(?!;)/use vars q($$1); $$1/o;' \
	    -e 'undef $$_ if /^\s*(no|use) warnings/o;' \
	    ${WRKSRC}/GCrypt.pm ${WRKSRC}/Makefile.PL
.endif

.include <bsd.port.post.mk>
