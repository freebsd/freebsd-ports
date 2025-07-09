PORTNAME=	opensmtpd-filter-rspamd
PORTVERSION=	0.1.8
DISTVERSIONPREFIX=	v
PORTREVISION=	14
CATEGORIES=	mail

MAINTAINER=	manu@FreeBSD.Org
COMMENT=	OpenSMTPD filter integration for the Rspamd daemon
WWW=		https://github.com/poolpOrg/filter-rspamd

LICENSE=	ISCL

RUN_DEPENDS=	opensmtpd>=6.6.0:mail/opensmtpd

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	poolpOrg
GH_PROJECT=	filter-rspamd

PLIST_FILES=	libexec/opensmtpd/opensmtpd-filter-rspamd

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/opensmtpd/
	${INSTALL_PROGRAM} ${WRKDIR}/bin/opensmtpd-filter-rspamd ${STAGEDIR}${PREFIX}/libexec/opensmtpd/

.include <bsd.port.mk>
