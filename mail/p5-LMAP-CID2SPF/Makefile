# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	LMAP-CID2SPF
DISTVERSION=	0.9
CATEGORIES=	mail perl5
MASTER_SITES=	http://www.baschny.de/spf/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Module to convert between Microsoft's Caller-ID and SPF		#'

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		perl5
USE_PERL5=	configure
CONFIGURE_SCRIPT=Makefile.PL

do-install:
	@${MKDIR} ${STAGEDIR}${SITE_PERL}/LMAP
	cd ${WRKSRC} && ${INSTALL_SCRIPT} cid2spf ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_DATA} CID2SPF.pm ${STAGEDIR}${SITE_PERL}/LMAP

.include <bsd.port.mk>
