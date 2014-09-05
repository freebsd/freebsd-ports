# $FreeBSD$

PORTNAME=	irrtoolset
PORTVERSION=	5.0.1
CATEGORIES=	net-mgmt
MASTER_SITES=	ISC/IRRToolSet/IRRToolSet-${PORTVERSION}

MAINTAINER=	rkoberman@gmail.com
COMMENT=	Suite of routing policy tools to interact with the IRR

PLIST_FILES=	bin/rpslcheck bin/peval bin/rtconfig \
		man/man1/rtconfig.1.gz man/man1/peval.1.gz \
		man/man1/rpslcheck.1.gz man/man1/irrtoolset-errors.1.gz

USES=		bison gmake libtool
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
