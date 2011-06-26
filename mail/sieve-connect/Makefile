# New ports collection makefile for:	sieve-connect
# Date created:				Sat 14 May 2011
# Whom:					Alexey V. Degtyarev <alexey@renatasystems.org>
#
# $FreeBSD$
#

PORTNAME=	sieve-connect
PORTVERSION=	0.81
CATEGORIES=	mail
MASTER_SITES=	http://people.spodhuis.org/phil.pennock/software/ \
		ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Command-line client for the MANAGESIEVE protocol

RUN_DEPENDS=	p5-Authen-SASL>=0:${PORTSDIR}/security/p5-Authen-SASL \
		p5-IO-Socket-INET6>=0:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-IO-Socket-SSL>=0:${PORTSDIR}/security/p5-IO-Socket-SSL \
		p5-Net-DNS>=0:${PORTSDIR}/dns/p5-Net-DNS \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey

LICENSE=	unknown
LICENSE_NAME=	Public Domain
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_BZIP2=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/${PORTNAME}

MAN1=		sieve-connect.1

.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog README TODO
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sieve-connect ${PREFIX}/bin/sieve-connect
	${INSTALL_MAN} ${WRKSRC}/sieve-connect.1 \
		${MANPREFIX}/man/man1/sieve-connect.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for _doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${_doc} ${DOCSDIR}/${_doc}
.endfor
.endif

.include <bsd.port.mk>
