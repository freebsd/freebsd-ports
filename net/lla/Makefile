# Created by: Sunagawa Koji <koj@ofug.net>
# $FreeBSD$

PORTNAME=	lla
PORTVERSION=	0.99.1
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.pl

MAINTAINER=	koj@ofug.net
COMMENT=	Perl-based LDAP log statistics generator

RUN_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc \
		p5-Date-Manip>=0:devel/p5-Date-Manip \
		p5-Time-modules>=0:devel/p5-Time-modules

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	lla
PLIST_FILES=	bin/lla

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	./${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
