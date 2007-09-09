# New ports collection makefile for:	p5-Crypt-GCrypt
# Date created:		2006-09-28
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-GCrypt
PORTVERSION=	1.16
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

post-extract:
	${RM} -f ${WRKSRC}/._Makefile.PL
	${RM} -f ${WRKSRC}/._GCrypt.pm
	${RM} -f ${WRKSRC}/._GCrypt.xs

.include <bsd.port.post.mk>
