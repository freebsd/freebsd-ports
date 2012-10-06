# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	stalepid
PORTVERSION=	1.0.b1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/sysutils/stalepid/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.b/pre/}

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Check for stale pid files and remove them

RUN_DEPENDS=	p5-Error>=0:${PORTSDIR}/lang/p5-Error

USE_PERL5_RUN=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}

MAN1=		stalepid.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/stalepid

.include <bsd.port.mk>
