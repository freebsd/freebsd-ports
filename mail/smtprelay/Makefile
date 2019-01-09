# $FreeBSD$

PORTNAME=	smtprelay
DISTVERSIONPREFIX=v
DISTVERSION=	1.2.0
CATEGORIES=	mail
MASTER_SITES=	https://code.bluelife.at/decke/smtprelay/archive/ \
		LOCAL/decke/smtprelay/
DISTFILES=	${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	decke@FreeBSD.org
COMMENT=	Simple Go SMTP relay/proxy server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go
USE_RC_SUBR=	smtprelay

USE_GITHUB=	nodefault
GH_TUPLE=	chrj:smtpd:v0.1.2:smtpd/vendor/github.com/chrj/smtpd \
		vharitonsky:iniflags:a33cd0b5f3de:iniflags/vendor/github.com/vharitonsky/iniflags \
		golang:crypto:505ab145d0a9:golang/vendor/golang.org/x/crypto

MAKE_ENV+=	GOFLAGS=-mod=vendor

PLIST_FILES=	bin/${PORTNAME} \
		"@sample ${ETCDIR}/smtprelay.ini.sample"

post-install:
		${MKDIR} ${STAGEDIR}${ETCDIR}
		${INSTALL_DATA} ${WRKSRC}/smtprelay.ini ${STAGEDIR}${ETCDIR}/smtprelay.ini.sample

.include <bsd.port.mk>
