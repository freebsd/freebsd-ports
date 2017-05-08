# Created by: pauls
# $FreeBSD$

PORTNAME=	chaosreader
PORTVERSION=	0.96
CATEGORIES=	security

MAINTAINER=	dbaio@FreeBSD.org
COMMENT=	Tool to extract data from tcpdump logs

LICENSE=	GPLv3+

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS

NO_BUILD=	yes
USES=		perl5 shebangfix
USE_PERL5=	run
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	brendangregg
GH_PROJECT=	Chaosreader

PLIST_FILES=	bin/${PORTNAME}
SHEBANG_FILES=	chaosreader

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
