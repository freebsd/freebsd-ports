# $FreeBSD$

PORTNAME=	irrtoolset
PORTVERSION=	5.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	ISC/IRRToolSet/IRRToolSet-${PORTVERSION}

MAINTAINER=	oberman@es.net
COMMENT=	A suite of routing policy tools to interact with the IRR

PLIST_FILES=	bin/rpslcheck bin/peval bin/rtconfig

USE_BISON=	build
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
MAKE_JOBS_SAFE=	yes

MAN1=		rtconfig.1 peval.1 rpslcheck.1 irrtoolset-errors.1

.include <bsd.port.mk>
