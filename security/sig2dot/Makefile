PORTNAME=	sig2dot
PORTVERSION=	0.35
CATEGORIES=	security
MASTER_SITES=	http://www.chaosreigns.com/code/sig2dot/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.pl

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPG/PGP Keyring Graph Generator

CONFLICTS_INSTALL=signing-party

PLIST_FILES=	bin/sig2dot
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	${WRKSRC}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	sig2dot.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sig2dot.pl ${STAGEDIR}${PREFIX}/bin/sig2dot

.include <bsd.port.mk>
