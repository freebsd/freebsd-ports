PORTNAME=	MogileFS-Server
PORTVERSION=	2.73
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DORMANDO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MogileFS (distributed filesystem) server
WWW=		https://metacpan.org/release/MogileFS-Server

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Danga-Socket>=1.56:devel/p5-Danga-Socket \
		p5-DBD-SQLite>=1.13:databases/p5-DBD-SQLite \
		${DBD_MYSQL} \
		p5-DBI>=0:databases/p5-DBI \
		p5-IO-AIO>=0:devel/p5-IO-AIO \
		p5-MogileFS-Client>=0:sysutils/p5-MogileFS-Client \
		p5-Net-Netmask>=0:net-mgmt/p5-Net-Netmask \
		p5-Perlbal>=1.79:www/perlbal \
		p5-Sys-Syscall>=0.22:devel/p5-Sys-Syscall

NO_ARCH=	yes
USES=		mysql perl5
USE_PERL5=	configure
REINPLACE_ARGS=	-i ''
USE_RC_SUBR=	mogilefsd mogstored

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
