# Created by: Anish Mistry <amistry@am-productions.biz>
# $FreeBSD$

PORTNAME=	atitvout
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	http://0pointer.de/lennart/projects/atitvout/ \
		http://am-productions.biz/docs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toggle TV Out on Mach64 graphics cards

LIB_DEPENDS=	lrmi:${PORTSDIR}/devel/lrmi

WRKSRC=		${WRKDIR}/atitvout
MAKEFILE=	Makefile.bsd

PLIST_FILES+=	sbin/atitvout

NO_STAGE=	yes
.include <bsd.port.mk>
