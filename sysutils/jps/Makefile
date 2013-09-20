# Created by: Pavel Novikov
# $FreeBSD$

PORTNAME=	jps
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ext.by/jps/

MAINTAINER=	pavel@ext.by
COMMENT=	Wrapper to ps(1) that maps pids to jails

BUILD_DEPENDS=	p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

MAN1=		jps.1
MANCOMPRESSED=	yes
USES=		perl5
PLIST_FILES=	bin/jps

NO_STAGE=	yes
.include <bsd.port.mk>
