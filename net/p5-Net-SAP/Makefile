# New ports collection makefile for:   p5-Net-SAP
# Date created:                                Jul 25 2004
# Whom:                                Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	Net-SAP
PORTVERSION=	0.02
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.ORG
COMMENT=	Session Announcement Protocol (rfc2974) packet parser

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/Socket/Multicast.pm:${PORTSDIR}/net/p5-IO-Socket-Multicast \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Net::SAP.3

.include <bsd.port.mk>
