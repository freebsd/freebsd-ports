# New ports collection makefile for:	p5-Brackup
# Date created:		2007-06-07
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	Brackup
PORTVERSION=	1.05
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Flexible backup tool

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1

PERL_CONFIGURE=	yes

MAN1=		brackup.1 brackup-restore.1 brackup-target.1
MAN3=		Brackup.3 Brackup::Config.3 Brackup::DigestCache.3 \
		Brackup::InventoryDatabase.3 Brackup::Manual::Overview.3 \
		Brackup::Root.3 Brackup::Target.3 Brackup::Target::Amazon.3 \
		Brackup::Target::Filesystem.3

.include <bsd.port.mk>
