# New ports collection makefile for:	p5-Net-SinFP
# Date created:		26 May 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME?=	Net-SinFP
PORTVERSION=	2.08
.ifdef DBDATE
PORTREVISION=	${DBDATE}
.endif
CATEGORIES=	security ipv6 perl5
MASTER_SITES=	CPAN
.ifdef DBDATE
MASTER_SITES+=	http://www.gomor.org/files/:DB
.endif
MASTER_SITE_SUBDIR=	CPAN:GOMOR
DISTNAME=	Net-SinFP-${PORTVERSION}
.ifdef DBDATE
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${DBDATE}.db:DB
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
.endif

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Full operating system stack fingerprinting suite

LICENSE=	ART10
LICENSE_FILE=	${WRKSRC}/LICENSE

.if ${PORTNAME} == "Net-SinFP"
PKGNAMEPREFIX=	p5-

BUILD_DEPENDS+=	p5-Class-Gomor>=1.00:${PORTSDIR}/devel/p5-Class-Gomor \
		p5-DBIx-SQLite-Simple>=0.33:${PORTSDIR}/databases/p5-DBIx-SQLite-Simple \
		p5-Net-Packet>=3.00:${PORTSDIR}/net/p5-Net-Packet \
		p5-Net-Packet-Target>=1.00:${PORTSDIR}/net/p5-Net-Packet-Target
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=	Net::SinFP.3 \
	Net::SinFP::Consts.3 \
	Net::SinFP::DB.3 \
	Net::SinFP::DB::IpVersion.3 \
	Net::SinFP::DB::Os.3 \
	Net::SinFP::DB::OsVersion.3 \
	Net::SinFP::DB::OsVersionChildren.3 \
	Net::SinFP::DB::OsVersionFamily.3 \
	Net::SinFP::DB::PatternBinary.3 \
	Net::SinFP::DB::PatternTcpFlags.3 \
	Net::SinFP::DB::PatternTcpMss.3 \
	Net::SinFP::DB::PatternTcpOptions.3 \
	Net::SinFP::DB::PatternTcpWindow.3 \
	Net::SinFP::DB::Signature.3 \
	Net::SinFP::DB::SystemClass.3 \
	Net::SinFP::DB::Vendor.3 \
	Net::SinFP::Result.3 \
	Net::SinFP::Search.3 \
	Net::SinFP::SinFP4.3 \
	Net::SinFP::SinFP6.3

post-patch:
	@${REINPLACE_CMD} -e 's/.*EXE_FILES.*//' ${WRKSRC}/${CONFIGURE_SCRIPT}

regression-test:
	@(cd ${WRKSRC} && ${PERL} ${CONFIGURE_SCRIPT} && ${MAKE} test)
.endif

ONLY_FOR_ARCHS=		i386 amd64 alpha
ONLY_FOR_ARCHS_REASON=	Big endian architectures not supported yet

.include <bsd.port.mk>
