# New ports collection makefile for:	p5-Crypt-GCrypt
# Date created:		2006-09-28
# Whom:			TAKAHASHI Kaoru <kaoru@kaisei.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-GCrypt
PORTVERSION=	1.24
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kaoru@kaisei.org
COMMENT=	Perl interface to the GNU Cryptographic library

LIB_DEPENDS=	gcrypt.17:${PORTSDIR}/security/libgcrypt

PERL_CONFIGURE=	5.6.0+
CONFIGURE_ARGS+=	GCRYPTLIBPATH=${LOCALBASE}/lib \
		GCRYPTINCPATH=${LOCALBASE}/include

MAN3=		Crypt::GCrypt.3 Crypt::GCrypt::MPI.3

.include <bsd.port.mk>
