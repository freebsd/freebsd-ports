# $FreeBSD$

PORTNAME=	Net-Nmsg
PORTVERSION=	0.15
CATEGORIES=	net perl5
MASTER_SITES=	https://tools.netsa.cert.org/confluence/download/attachments/12320770/ \
		CPAN
MASTER_SITE_SUBDIR=	CPAN:MSISK
PKGNAMEPREFIX=	p5-

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Net::Nmsg is a perl binding to libnmsg

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libnmsg.so:net/nmsg
RUN_DEPENDS=	p5-Math-Int64>=0:math/p5-Math-Int64 \
		p5-NetAddr-IP>=0:net-mgmt/p5-NetAddr-IP

USES=		perl5
MAKE_JOBS_UNSAFE=	yes
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Net/Nmsg/Nmsg.so

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
