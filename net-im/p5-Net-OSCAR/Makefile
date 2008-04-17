# New ports collection makefile for:	p5-Net-OSCAR
# Date created:				26 Sep 2004
# Whom:					Kelly Cochran <kcochran@trolans.net>
#
# $FreeBSD$
#

PORTNAME=	Net-OSCAR
PORTVERSION=	1.925
CATEGORIES=	net-im perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for the AOL Instant Messenger OSCAR protocol

PERL_MODBUILD=	yes

MAN3=	Net::OSCAR.3 \
	Net::OSCAR::Buddylist.3 \
	Net::OSCAR::Callbacks.3 \
	Net::OSCAR::Common.3 \
	Net::OSCAR::Connection.3 \
	Net::OSCAR::Connection::Chat.3 \
	Net::OSCAR::Connection::Direct.3 \
	Net::OSCAR::Connection::Server.3 \
	Net::OSCAR::Constants.3 \
	Net::OSCAR::MethodInfo.3 \
	Net::OSCAR::Screenname.3 \
	Net::OSCAR::ServerCallbacks.3 \
	Net::OSCAR::TLV.3 \
	Net::OSCAR::Utility.3 \
	Net::OSCAR::XML.3 \
	Net::OSCAR::_BLInternal.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Scalar/Util.pm:${PORTSDIR}/lang/p5-Scalar-List-Utils
.endif

.include <bsd.port.post.mk>
