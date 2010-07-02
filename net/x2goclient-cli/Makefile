# New ports collection makefile for:	x2goclient-cli
# Date created:				2010-06-24
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	x2goclient-cli
DISTVERSION=	3.0.1-1.2
CATEGORIES=	net
MASTER_SITES=	http://x2go.obviously-nice.de/deb/pool-lenny/x2goclient-cli/
DISTNAME=	${PORTNAME}_${DISTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	The x2go perl client

RUN_DEPENDS=	${SITE_PERL}/Proc/Simple.pm:${PORTSDIR}/devel/p5-Proc-Simple \
		${SITE_PERL}/Term/ReadPassword.pm:${PORTSDIR}/devel/p5-Term-ReadPassword \
		nxproxy:${PORTSDIR}/net/nxproxy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE
USE_PERL5=	yes
PLIST_FILES=	bin/x2goclient-cli bin/setsid
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S,-1.2,,}

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${FILESDIR}/setsid.c -o setsid

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/x2goclient-cli ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/setsid ${PREFIX}/bin

.include <bsd.port.mk>
