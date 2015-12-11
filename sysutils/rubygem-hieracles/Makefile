# $FreeBSD$

PORTNAME=	hieracles
PORTVERSION=	0.2.2
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	mose@gandi.net
COMMENT=	CLI tool for Hiera parameters visualisation and analysis

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-deep_merge>=1.0.1:${PORTSDIR}/devel/rubygem-deep_merge \
		rubygem-awesome_print>=1.6.1:${PORTSDIR}/devel/rubygem-awesome_print \
		rubygem-httparty>=0.13.7:${PORTSDIR}/www/rubygem-httparty

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/hc man/man1/hc.1.gz \
		bin/ppdb man/man1/ppdb.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/hc.1 ${STAGEDIR}${PREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/ppdb.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
