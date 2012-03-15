# New ports collection makefile for:    p5-File-KeePass
# Date created:				2012-03-10
# Whom:					Alexander Y. Grigoryev <alexander.4mail@gmail.com>
#
# $FreeBSD$

PORTNAME=	File-KeePass
PORTVERSION=	0.03
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	alexander.4mail@gmail.com
COMMENT=	Interface to KeePass V1 and KeePassX database files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Crypt-Rijndael>=1.0:${PORTSDIR}/security/p5-Crypt-Rijndael
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		File::KeePass.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501000
BUILD_DEPENDS+=	p5-Digest-SHA>=1.0:${PORTSDIR}/security/p5-Digest-SHA
RUN_DEPENDS+=	p5-Digest-SHA>=1.0:${PORTSDIR}/security/p5-Digest-SHA
.endif

.include <bsd.port.post.mk>
