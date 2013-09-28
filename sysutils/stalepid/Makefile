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

USES=		perl5
USE_PERL5=	run

WRKSRC=		${WRKDIR}/${DISTNAME}

PLIST_FILES=	bin/stalepid man/man1/stalepid.1.gz

.include <bsd.port.mk>
