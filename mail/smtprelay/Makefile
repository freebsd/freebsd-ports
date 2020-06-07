# $FreeBSD$

PORTNAME=	smtprelay
DISTVERSIONPREFIX=v
DISTVERSION=	1.4.0
CATEGORIES=	mail

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Simple Go SMTP relay/proxy server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	smtprelay

USE_GITHUB=	yes
GH_ACCOUNT=	decke

GH_TUPLE=	chrj:smtpd:v0.2.0:chrj_smtpd/vendor/github.com/chrj/smtpd \
		golang:crypto:70a84ac30bf9:golang_crypto/vendor/golang.org/x/crypto \
		vharitonsky:iniflags:a33cd0b5f3de:vharitonsky_iniflags/vendor/github.com/vharitonsky/iniflags

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR}/smtprelay.ini.sample"

post-install:
		${MKDIR} ${STAGEDIR}${ETCDIR}
		${INSTALL_DATA} ${WRKSRC}/smtprelay.ini ${STAGEDIR}${ETCDIR}/smtprelay.ini.sample

.include <bsd.port.mk>
