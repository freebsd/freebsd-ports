# New ports collection makefile for:	mldonkey perlreactor
# Date created:				Sat Feb 23 13:13:08 BRT 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mldonkey
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	remotefilesync
PKGNAMESUFFIX=	-perlreactor
DISTNAME=	perlreactor_${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Automatically add links found in web pages to MLDonkey queue

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

USE_PERL5=	yes
USE_SIZE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

BINARY_NAME=	perlreactor

post-patch:
	@${PERL} -pi -e 's|#!/usr/bin/perl\n||; \
		s|/usr/local/bin/perl|${PERL}|' \
		${WRKSRC}/${BINARY_NAME}

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${CHMOD} 0755 ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
	@${INSTALL_DATA} ${WRKDIR}/README ${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin

post-install:
	@${SED} -e 's|/usr/local/|${PREFIX}/|' ${PKGMESSAGE}

.include <bsd.port.mk>
