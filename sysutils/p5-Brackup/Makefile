# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Brackup
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible backup tool

BUILD_DEPENDS=	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-DateTime-Format-ISO8601>0:${PORTSDIR}/devel/p5-DateTime-Format-ISO8601 \
		p5-Digest-SHA1>0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Fuse>0:${PORTSDIR}/sysutils/p5-Fuse \
		p5-IO-stringy>0:${PORTSDIR}/devel/p5-IO-stringy \
		p5-Net-Amazon-S3>0:${PORTSDIR}/net/p5-Net-Amazon-S3 \
		p5-Net-SFTP>0:${PORTSDIR}/net/p5-Net-SFTP \
		p5-String-Escape>0:${PORTSDIR}/textproc/p5-String-Escape
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
