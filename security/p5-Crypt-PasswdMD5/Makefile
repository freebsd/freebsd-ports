# New ports collection makefile for:	p5-Crypt-PasswdMD5
# Date created:				18 June, 2002
# Whom:					Erwin Lansing <erwin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Crypt-PasswdMD5
PORTVERSION=	1.3
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Crypt
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Perl module that provides interoperable MD5-based crypt() function

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes
PERL_CONFIGURE=	yes

MAN3=		Crypt::PasswdMD5.3

pre-patch:
	@${REINPLACE_CMD} -e 's|[[:cntrl:]]$$||g' ${WRKSRC}/PasswdMD5.pm

.include <bsd.port.mk>
