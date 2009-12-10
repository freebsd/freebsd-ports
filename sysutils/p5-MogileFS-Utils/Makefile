# New ports collection makefile for:	p5-MogileFS-Utils
# Date created:		2007-04-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	MogileFS-Utils
PORTVERSION=	2.15
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/D/DO/DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	MogileFS tools

RUN_DEPENDS=	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/MogileFS/Client.pm:${PORTSDIR}/sysutils/p5-MogileFS-Client

PERL_CONFIGURE=	yes

MAN1=		mogadm.1 mogtool.1
MAN3=		MogileFS::Utils.3

.include <bsd.port.mk>
