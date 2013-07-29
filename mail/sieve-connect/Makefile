# Created by: Alexey V. Degtyarev <alexey@renatasystems.org>
# $FreeBSD$

PORTNAME=	sieve-connect
PORTVERSION=	0.86
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
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

USE_BZIP2=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/sieve-connect

MAN1=		sieve-connect.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	ChangeLog README.md TODO
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sieve-connect ${PREFIX}/bin/sieve-connect
	${INSTALL_MAN} ${WRKSRC}/sieve-connect.1 \
		${MANPREFIX}/man/man1/sieve-connect.1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
