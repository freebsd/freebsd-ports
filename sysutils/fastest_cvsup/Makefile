# Created by: A.J.Robinson (ajr@subdimension.com)
# $FreeBSD$

PORTNAME=	fastest_cvsup
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:S/_/-/}

MAINTAINER=	freebsd@hm2k.org
COMMENT=	Finds fastest CVSup server

LICENSE=	BSD

USES=		perl5 shebangfix
SHEBANG_FILES=	fastest_cvsup

PLIST_FILES=	bin/fastest_cvsup man/man7/fastest_cvsup.7.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/fastest_cvsup ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fastest_cvsup.7 ${STAGEDIR}${PREFIX}/man/man7

.include <bsd.port.mk>
