# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	sieve-connect
PORTVERSION=	0.87
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://people.spodhuis.org/phil.pennock/software/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Command-line client for the MANAGESIEVE protocol

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL \
		p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6 \
		p5-IO-Socket-SSL>=1.14:security/p5-IO-Socket-SSL \
		p5-Mozilla-PublicSuffix>=0:dns/p5-Mozilla-PublicSuffix \
		p5-Net-DNS>=0:dns/p5-Net-DNS \
		p5-Net-SSLeay>=1.37:security/p5-Net-SSLeay \
		p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

USES=		perl5 tar:bzip2 shebangfix
SHEBANG_FILES=	sieve-connect.pl

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
