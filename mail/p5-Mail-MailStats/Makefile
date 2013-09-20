# Created by: will
# $FreeBSD$

PORTNAME=	MailStats
PORTVERSION=	0.02
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chifeng@gmail.com
COMMENT=	Perl module to detect newer messages in procmail-generated mailboxes

BUILD_DEPENDS=	p5-AppConfig>=0:${PORTSDIR}/devel/p5-AppConfig
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Mail::Stats::Record.3 Mail::Stats.3

NO_STAGE=	yes
.include <bsd.port.mk>
