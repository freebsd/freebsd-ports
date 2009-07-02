# New ports collection makefile for:   scnc
# Date created:                        27 April 2008
# Whom:                                Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	scnc
PORTVERSION=	1.03
CATEGORIES=	net security
MASTER_SITES=	http://gomor.org/files/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	# none
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbrabez@gmail.com
COMMENT=	SSL Capable Netcat

RUN_DEPENDS=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL \
		${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6
BUILD_DEPENDS=	${RUN_DEPENDS}

PLIST_FILES=	bin/${PORTNAME}
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${_DISTDIR}/scnc ${WRKSRC}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
