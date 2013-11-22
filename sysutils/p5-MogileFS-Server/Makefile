# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	MogileFS-Server
PORTVERSION=	2.70
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	trociny@FreeBSD.org
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

USES=		perl5
USE_PERL5=	configure
REINPLACE_ARGS=	-i ''
USE_RC_SUBR=	mogilefsd mogstored

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
