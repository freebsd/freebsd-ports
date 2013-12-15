# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	sieve-connect
PORTVERSION=	0.87
CATEGORIES=	mail
MASTER_SITES=	http://people.spodhuis.org/phil.pennock/software/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Command-line client for the MANAGESIEVE protocol

LICENSE=	unknown
LICENSE_NAME=	Public Domain
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-IO-Socket-SSL>=1.14:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Mozilla-PublicSuffix>=0:${PORTSDIR}/dns/p5-Mozilla-PublicSuffix \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-SSLeay>=1.37:${PORTSDIR}/security/p5-Net-SSLeay \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

USES=		perl5
USE_BZIP2=	yes

PLIST_FILES=	bin/sieve-connect \
		man/man1/sieve-connect.1.gz

PORTDOCS=	ChangeLog README.md TODO

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sieve-connect \
		${STAGEDIR}${PREFIX}/bin/sieve-connect
	${INSTALL_MAN} ${WRKSRC}/sieve-connect.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/sieve-connect.1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
