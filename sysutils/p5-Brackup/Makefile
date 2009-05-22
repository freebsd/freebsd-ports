# New ports collection makefile for:	p5-Brackup
# Date created:		2007-06-07
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Brackup
PORTVERSION=	1.09
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible backup tool

RUN_DEPENDS=	p5-DBD-SQLite>0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>0:${PORTSDIR}/databases/p5-DBI \
		p5-Digest-SHA1>0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-MP3-Info>0:${PORTSDIR}/audio/p5-MP3-Info \
		p5-Net-Amazon-S3>0:${PORTSDIR}/net/p5-Net-Amazon-S3 \
		p5-Net-SFTP>0:${PORTSDIR}/net/p5-Net-SFTP

PERL_CONFIGURE=	yes

MAN1=		brackup.1 \
		brackup-restore.1 \
		brackup-target.1
MAN3=		Brackup.3 \
		Brackup::Chunker::MP3.3 \
		Brackup::Config.3 \
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
		Brackup::Target::Sftp.3

.include <bsd.port.mk>
