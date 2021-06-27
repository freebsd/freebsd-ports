# Created by: arved

PORTNAME=	x2goclient-cli
DISTVERSION=	3.0.1-1.2
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	http://x2go.obviously-nice.de/deb/pool-lenny/x2goclient-cli/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	nc@FreeBSD.org
COMMENT=	The x2go perl client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Proc-Simple>=0:devel/p5-Proc-Simple \
		p5-Term-ReadPassword>=0:devel/p5-Term-ReadPassword \
		nxproxy:net/nxproxy \
		setsid:sysutils/setsid

USES=		perl5 shebangfix
SHEBANG_FILES=	x2goclient-cli
PLIST_FILES=	bin/x2goclient-cli
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S,-1.2,,}
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/x2goclient-cli ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
