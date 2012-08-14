# New ports collection makefile for:	p5-mogilefs-server
# Date created:		2007-04-28
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	MogileFS-Server
PORTVERSION=	2.65
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MogileFS (distributed filesystem) server

BUILD_DEPENDS=	p5-Danga-Socket>=1.56:${PORTSDIR}/devel/p5-Danga-Socket \
		p5-DBD-SQLite>=1.13:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-IO-AIO>=0:${PORTSDIR}/devel/p5-IO-AIO \
		p5-MogileFS-Client>=0:${PORTSDIR}/sysutils/p5-MogileFS-Client \
		p5-Net-Netmask>=0:${PORTSDIR}/net-mgmt/p5-Net-Netmask \
		p5-Perlbal>=1.79:${PORTSDIR}/www/perlbal \
		p5-Sys-Syscall>=0.22:${PORTSDIR}/devel/p5-Sys-Syscall \
		p5-Sys-Syslog>=0:${PORTSDIR}/sysutils/p5-Sys-Syslog
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS

PERL_CONFIGURE=	yes
REINPLACE_ARGS=	-i ''
USE_RC_SUBR=	mogilefsd mogstored

MAN1=		mogautomount.1 \
		mogilefsd.1 \
		mogstored.1
MAN3=		MogileFS::Checksum.3 \
		MogileFS::Class.3 \
		MogileFS::DevFID.3 \
		MogileFS::Device.3 \
		MogileFS::Domain.3 \
		MogileFS::FID.3 \
		MogileFS::Factory.3 \
		MogileFS::Host.3 \
		MogileFS::IOStatWatcher.3 \
		MogileFS::Overview.3 \
		MogileFS::ReplicationPolicy.3 \
		MogileFS::ReplicationPolicy::MultipleHosts.3 \
		MogileFS::ReplicationPolicy::Union.3 \
		MogileFS::Server.3 \
		MogileFS::Store.3 \
		MogileFS::Store::MySQL.3 \
		MogileFS::Store::Postgres.3 \
		MogileFS::Store::SQLite.3 \
		MogileFS::Worker::Query.3 \
		MogileFS::Worker::Replicate.3

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}/
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
TEST_DEPENDS+=	p5-Test-Simple>=0.88:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
