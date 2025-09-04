PORTNAME=	smtprelay
DISTVERSIONPREFIX=v
DISTVERSION=	1.12.0
PORTREVISION=	4
CATEGORIES=	mail

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Simple Go SMTP relay/proxy server
WWW=		https://github.com/decke/smtprelay

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
GO_MODULE=	github.com/decke/smtprelay

USE_RC_SUBR=	smtprelay

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR}/smtprelay.ini.sample"

post-install:
		${MKDIR} ${STAGEDIR}${ETCDIR}
		${INSTALL_DATA} ${WRKSRC}/smtprelay.ini ${STAGEDIR}${ETCDIR}/smtprelay.ini.sample

.include <bsd.port.mk>
