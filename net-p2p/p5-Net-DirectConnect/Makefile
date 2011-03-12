# New ports collection makefile for:	p5-Net-DirectConnect
# Date created:		2010-01-16
# Whom:			Oleg Alexeenkov <proler@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net-DirectConnect
PORTVERSION=	0.09
CATEGORIES=	net-p2p net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/P/PR/PRO/
PKGNAMEPREFIX=	p5-

MAINTAINER=	proler@gmail.com
COMMENT=	Perl Direct Connect lib and client

RUN_DEPENDS=	${SITE_PERL}/lib/abs.pm:${PORTSDIR}/devel/p5-lib-abs \
		${SITE_PERL}/MIME/Base32.pm:${PORTSDIR}/converters/p5-MIME-Base32 \
		${SITE_PERL}/${PERL_ARCH}/Sys/Sendfile/FreeBSD.pm:${PORTSDIR}/devel/p5-Sys-Sendfile-FreeBSD \
		${SITE_PERL}/${PERL_ARCH}/Net/DirectConnect/TigerHash.pm:${PORTSDIR}/net-p2p/p5-Net-DirectConnect-TigerHash \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite

PERL_CONFIGURE=	yes

MAN1=		dcget.1 dcshare.1
MAN3=		Net::DirectConnect.3 Net::DirectConnect::filelist.3

.include <bsd.port.mk>
