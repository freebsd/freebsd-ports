# Created by: ijliao
# $FreeBSD$

PORTNAME=	sig2dot
PORTVERSION=	0.35
CATEGORIES=	security
MASTER_SITES=	http://www.chaosreigns.com/code/sig2dot/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPG/PGP Keyring Graph Generator

CONFLICTS_INSTALL=signing-party-[0-9]*

PLIST_FILES=	bin/sig2dot
USE_PERL5=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		shebangfix
SHEBANG_FILES=	sig2dot.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sig2dot.pl ${PREFIX}/bin/sig2dot

.include <bsd.port.mk>
