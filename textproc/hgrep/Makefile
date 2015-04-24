# Created by: Aaron Zauner <az_mail@gmx.at>
# $FreeBSD$

PORTNAME=	hgrep
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://www.acme.com/software/hgrep/
DISTNAME=	${PORTNAME}_04oct1999

MAINTAINER=	azet@azet.org
COMMENT=	Nice Highlighting Hack for grep

WRKSRC=		${WRKDIR}/hgrep

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} > 1000000 && ${ARCH} == amd64
BROKEN=		does not build on 10.x+ amd64
.endif

DEPRECATED=	Not needed any more: base grep has coloring support
EXPIRATION_DATE=	2015-05-31

.include <bsd.port.post.mk>
