PORTNAME=	opensmtpd-filter-senderscore
PORTVERSION=	0.1.2
PORTREVISION=	27
CATEGORIES=	mail

MAINTAINER=	manu@FreeBSD.Org
COMMENT=	OpenSMTPD filter integration for the senderscore reputation
WWW=		https://github.com/poolpOrg/filter-senderscore

LICENSE=	ISCL

RUN_DEPENDS=	opensmtpd>=6.6.0:mail/opensmtpd

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	poolpOrg
GH_PROJECT=	filter-senderscore

PLIST_FILES=	libexec/opensmtpd/opensmtpd-filter-senderscore

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/opensmtpd/
	${INSTALL_PROGRAM} ${WRKDIR}/bin/opensmtpd-filter-senderscore ${STAGEDIR}${PREFIX}/libexec/opensmtpd/

.include <bsd.port.mk>
