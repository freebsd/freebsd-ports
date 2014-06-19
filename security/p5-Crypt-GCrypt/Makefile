# Created by: TAKAHASHI Kaoru <kaoru@kaisei.org>
# $FreeBSD$

PORTNAME=	Crypt-GCrypt
PORTVERSION=	1.26
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to the GNU Cryptographic library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

CONFIGURE_ARGS=	GCRYPTINCPATH=${LOCALBASE}/include \
		GCRYPTLIBPATH=${LOCALBASE}/lib
USE_PERL5=	configure
USES=		perl5

.include <bsd.port.mk>
