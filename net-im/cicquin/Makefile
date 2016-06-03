# Created by: Peter Pentchev
# $FreeBSD$

PORTNAME=	cicquin
PORTVERSION=	0.1
CATEGORIES=	net-im
#MASTER_SITES=	LOCAL/roam/misc/cicquin \
MASTER_SITES=	\
		http://devel.ringlet.net/misc/cicquin/ \
		http://people.FreeBSD.org/~roam/misc/cicquin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Look up users in the CenterICQ user database

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
