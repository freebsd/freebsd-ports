# $FreeBSD$

PORTNAME=	bluemix-cli
PORTVERSION=	0.4.4
DISTNAME=	Bluemix_CLI_${PORTVERSION}_386
CATEGORIES=	net
MASTER_SITES=	http://public.dhe.ibm.com/cloud/${PORTNAME:C/-.*//}/cli/${PORTNAME}/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Bluemix command line interface

LICENSE=	BLUEMIX
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME=	IBM Bluemix Service Description
LICENSE_FILE=	${WRKSRC}/bin/LICENSE

RUN_DEPENDS=	cf:net/cf

USES=		linux
NO_BUILD=	yes
NO_ARCH=	yes
STRIP=		# empty

WRKSRC=		${WRKDIR}/Bluemix_CLI

PLIST_FILES=	bin/bluemix bin/bluemix-analytics bin/bx \
		etc/bash_completion.d/bluemix.sh

pre-install:
	${BRANDELF} -t Linux ${WRKSRC}/bin/bluemix*

do-install:
	cd ${WRKSRC}/bin && ${INSTALL_PROGRAM} bluemix bluemix-analytics \
		${STAGEDIR}${PREFIX}/bin
	${LN} -s bluemix ${STAGEDIR}${PREFIX}/bin/bx
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bx/bash_autocomplete ${STAGEDIR}${PREFIX}/etc/bash_completion.d/bluemix.sh

.include <bsd.port.mk>
