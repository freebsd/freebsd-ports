# Created by: TANAKA Takashi <tanaka@tahi.org>
# $FreeBSD$

PORTNAME=	v6eval
PORTVERSION=	3.3.2
PORTEPOCH=	1
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tahi.org/release/v6eval/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPv6 Conformance Test Platform

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

RUN_DEPENDS=	p5-Expect>=0:${PORTSDIR}/lang/p5-Expect

USE_PERL5=	yes
USE_OPENSSL=	yes
MAKE_JOBS_SAFE=	yes
SUB_FILES=	pkg-message

NO_MANCOMPRESS=	yes
MAN1PREFIX=	${PREFIX}/v6eval
MAN3PREFIX=	${LOCALBASE}/lib/perl5/${PERL_VER}
MAN1=		pktctl.1.gz pktsend.1.gz
MAN3=		V6evalRemote.3 V6evalTool.3

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
