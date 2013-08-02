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

MAN1=		brackup.1 \
		brackup-mount.1 \
		brackup-restore.1 \
		brackup-target.1 \
		brackup-verify-inventory.1
MAN3=		Brackup.3 \
		Brackup::Chunker::MP3.3 \
		Brackup::Config.3 \
		Brackup::Dict::Null.3 \
		Brackup::Dict::SQLite.3 \
		Brackup::Dict::SQLite2.3 \
		Brackup::DigestCache.3 \
		Brackup::InventoryDatabase.3 \
		Brackup::Manual::Overview.3 \
		Brackup::Mount.3 \
		Brackup::Root.3 \
		Brackup::Target.3 \
		Brackup::Target::Amazon.3 \
		Brackup::Target::CloudFiles.3 \
		Brackup::Target::Filesystem.3 \
		Brackup::Target::Ftp.3 \
		Brackup::Target::GoogleAppEngine.3 \
		Brackup::Target::Riak.3 \
		Brackup::Target::Sftp.3

.include <bsd.port.mk>
