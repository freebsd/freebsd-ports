PORTNAME=	hieracles
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	sysutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CLI tool for Hiera parameters visualisation and analysis
WWW=		https://github.com/Gandi/hieracles/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-deep_merge>=1.0.1:devel/rubygem-deep_merge \
		rubygem-awesome_print>=1.6.1:devel/rubygem-awesome_print \
		rubygem-httparty>=0.13.7:www/rubygem-httparty

NO_ARCH=	yes
USES=		gem

CONFLICTS_INSTALL=	zh-hc # bin/hc

PLIST_FILES=	bin/hc share/man/man1/hc.1.gz \
		bin/ppdb share/man/man1/ppdb.1.gz \
		bin/hieracles

post-install:
	${INSTALL_MAN} ${WRKSRC}/hc.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${INSTALL_MAN} ${WRKSRC}/ppdb.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
