# New ports collection makefile for:	SinFP
# Date created:		26 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-SinFP
PORTVERSION=	2.02.1
DISTVERSION=	2.02
PORTREVISION=	1
CATEGORIES=	security ipv6 perl5
MASTER_SITES=	CPAN

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Full operating system stack fingerprinting suite

BUILD_DEPENDS=	p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor \
		p5-DBIx-SQLite-Simple>=0.33:${PORTSDIR}/databases/p5-DBIx-SQLite-Simple \
		p5-Net-Packet>=3.00:${PORTSDIR}/net/p5-Net-Packet \
		p5-Net-Packet-Target>=1.00:${PORTSDIR}/net/p5-Net-Packet-Target
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
MAN3=	Net::SinFP.3 Net::SinFP::Consts.3 Net::SinFP::DB.3 Net::SinFP::DB::IpVersion.3 \
	Net::SinFP::DB::Os.3 Net::SinFP::DB::OsVersion.3 Net::SinFP::DB::OsVersionChildren.3 \
	Net::SinFP::DB::OsVersionFamily.3 Net::SinFP::DB::PatternBinary.3 \
	Net::SinFP::DB::PatternTcpFlags.3 Net::SinFP::DB::PatternTcpMss.3 \
	Net::SinFP::DB::PatternTcpOptions.3 Net::SinFP::DB::PatternTcpWindow.3 \
	Net::SinFP::DB::Signature.3 Net::SinFP::DB::SystemClass.3 Net::SinFP::DB::Vendor.3 \
	Net::SinFP::Result.3 Net::SinFP::Search.3 Net::SinFP::SinFP4.3 Net::SinFP::SinFP6.3

ONLY_FOR_ARCHS=		i386 amd64 alpha
ONLY_FOR_ARCHS_REASON=	Big endian architectures not supported yet

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500601
IGNORE=	perl 5.6.1 or newer required. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
