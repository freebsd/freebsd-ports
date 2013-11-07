# Created by: mat
# $FreeBSD$

PORTNAME=	HTTP-Recorder
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Record interaction with websites

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-HTTP-Proxy>=0:${PORTSDIR}/www/p5-HTTP-Proxy \
		p5-HTTP-Request-Params>=0:${PORTSDIR}/www/p5-HTTP-Request-Params \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_DOS2UNIX=	yes

post-patch:
	@${RM} -f ${WRKSRC}/lib/HTTP/Recorder.pm.orig

.include <bsd.port.mk>
