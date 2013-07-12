# Created by: Max Khon
# $FreeBSD$

PORTNAME=	base
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	news mail
MASTER_SITES=	SF/husky/huskybase/${PORTVERSION}
DISTNAME=	huskybase-${PORTVERSION}-src

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	Common files for Husky Fidosoft Project

CONFLICTS=	husky-base-devel-[0-9]*

WRKSRC=		${WRKDIR}/huskybse
NO_BUILD=	yes

USERS=		fido
GROUPS=		fido

do-install:
	@${MKDIR} ${PREFIX}/etc/fido ${PREFIX}/share/doc/husky
	@${CHOWN} fido:fido ${PREFIX}/etc/fido
	@${INSTALL_DATA} ${WRKSRC}/huskymak.cfg ${PREFIX}/etc/fido

.include "${.CURDIR}/../husky-base/Makefile.inc"
.include <bsd.port.mk>
