PORTNAME=	agate
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.19
CATEGORIES=	www

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Simple static file server in Rust for the Gemini network protocol
WWW=		https://github.com/mbrubeck/agate/

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	mbrubeck
USE_RC_SUBR=	agate

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}/tls
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}/var/log/agate

.include <bsd.port.mk>
