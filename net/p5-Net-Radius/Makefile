# New ports collection makefile for:	p5-Net-Radius
# Date created:				20 Mar 2002
# Whom:                			Kelly Yancey <kbyanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Radius
PORTVERSION=	1.43
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	kbyanc@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=		Net::Radius::Dictionary.3 Net::Radius::Packet.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-extract:
	find ${WRKDIR} -type f | xargs perl -pi -e "s:\r::g"

.include <bsd.port.mk>
