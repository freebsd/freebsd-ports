# $FreeBSD$

PORTNAME=	viamillipede
PORTVERSION=	0.7
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	ash_ports@aeria.net
COMMENT=	Parallel TCP for pipe transport

LICENSE=	BSD3CLAUSE

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	agokhale

PLIST_FILES=	bin/viamillipede man/man1/viamillipede.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1004000
BROKEN=		Needs bsd.prog.mk features from at least 10.4, otherwise referenced /usr/share/mk/bsd.own.mk line 505: MK_DEBUG_FILES can't be set by a user.
.endif

.include <bsd.port.post.mk>
