# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	Net-SSLeay
PORTVERSION=	1.55
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to SSL

TEST_DEPENDS=	p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-NoWarnings>=0:${PORTSDIR}/devel/p5-Test-NoWarnings \
		p5-Test-Warn>=0:${PORTSDIR}/devel/p5-Test-Warn

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ENV=	OPENSSL_PREFIX=${OPENSSLBASE}
REINPLACE_ARGS=	-i ''
USE_OPENSSL=	yes

PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -e '1 s|/usr/bin/perl|${PERL}|' ${WRKSRC}/examples/*.pl
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/examples/*.pl ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/req.conf ${STAGEDIR}${EXAMPLESDIR}/req.conf
.endif

.include <bsd.port.mk>
