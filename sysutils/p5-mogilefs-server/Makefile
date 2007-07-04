# New ports collection makefile for:	p5-mogilefs-server
# Date created:		2007-04-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	mogilefs-server
PORTVERSION=	2.16
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	MogileFS (distributed filesystem) server

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/AIO.pm:${PORTSDIR}/devel/p5-IO-AIO \
		${SITE_PERL}/Danga/Socket.pm:${PORTSDIR}/devel/p5-Danga-Socket \
		${SITE_PERL}/Net/Netmask.pm:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		${SITE_PERL}/Perlbal.pm:${PORTSDIR}/www/perlbal \
		${SITE_PERL}/Sys/Syscall.pm:${PORTSDIR}/devel/p5-Sys-Syscall

PERL_CONFIGURE=	yes

MAN1=		mogautomount.1 mogilefsd.1 mogstored.1
MAN3=		MogileFS::DevFID.3 MogileFS::FID.3 MogileFS::IOStatWatcher.3 \
		MogileFS::Overview.3 MogileFS::ReplicationPolicy.3 \
		MogileFS::ReplicationPolicy::MultipleHosts.3 \
		MogileFS::Server.3 MogileFS::Store.3 \
		MogileFS::Store::MySQL.3 MogileFS::Store::SQLite.3 \
		MogileFS::Worker::Query.3 MogileFS::Worker::Replicate.3

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
