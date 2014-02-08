# Created by: Sunagawa Koji <koj@ofug.net>
# $FreeBSD$

PORTNAME=	lla
PORTVERSION=	0.99.1
CATEGORIES=	net perl5
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.pl

MAINTAINER=	koj@ofug.net
COMMENT=	Perl-based LDAP log statistics generator

RUN_DEPENDS=	p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Time-modules>=0:${PORTSDIR}/devel/p5-Time-modules

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USES=		perl5
PLIST_FILES=	bin/lla

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	
EXTRACT_AFTER_ARGS=	./${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
