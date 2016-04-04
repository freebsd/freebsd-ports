# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	Brackup
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible backup tool

BUILD_DEPENDS=	p5-DBD-SQLite>0:databases/p5-DBD-SQLite \
		p5-DBI>0:databases/p5-DBI \
		p5-DateTime-Format-ISO8601>0:devel/p5-DateTime-Format-ISO8601 \
		p5-Digest-SHA1>0:security/p5-Digest-SHA1 \
		p5-Fuse>0:sysutils/p5-Fuse \
		p5-IO-stringy>0:devel/p5-IO-stringy \
		p5-Net-Amazon-S3>0:net/p5-Net-Amazon-S3 \
		p5-Net-SFTP>0:net/p5-Net-SFTP \
		p5-String-Escape>0:textproc/p5-String-Escape
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
