# $FreeBSD$

PORTNAME=	icingaweb2-module-pdfexport
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	net-mgmt www

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Icinga PDF Export

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	icingaweb2>=2.4.1:net-mgmt/icingaweb2 \
		chromium>0:www/chromium

USE_GITHUB=	yes
GH_ACCOUNT=	icinga

NO_BUILD=	yes
NO_ARCH=	yes

WWWDIR?=	${PREFIX}/www/icingaweb2/modules/${PORTNAME:C/^.*-//}

post-patch:
	@${REINPLACE_CMD} -e "s|/bin/google-chrome|${LOCALBASE}/bin/chrome|" \
		${WRKSRC}/library/Pdfexport/ProvidedHook/Pdfexport.php
do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
