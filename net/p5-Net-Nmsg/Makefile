# $FreeBSD$

PORTNAME=	Net-Nmsg
PORTVERSION=	0.12
CATEGORIES=	net perl5
MASTER_SITES=	https://tools.netsa.cert.org/confluence/download/attachments/12320770/ \
		http://tools.netsa.cert.org/confluence/download/attachments/12320770/
PKGNAMEPREFIX=	p5-

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Net::Nmsg is a perl binding to libnmsg

LICENSE=	GPLv2

LIB_DEPENDS=	libnmsg.so:${PORTSDIR}/net/nmsg
RUN_DEPENDS=	p5-Math-Int64>=0:${PORTSDIR}/math/p5-Math-Int64 \
		p5-NetAddr-IP>=0:${PORTSDIR}/net-mgmt/p5-NetAddr-IP

USES=		perl5
MAKE_JOBS_UNSAFE=	yes
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Net/Nmsg/Nmsg.so
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
