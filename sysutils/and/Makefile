# Created by: ijliao
# $FreeBSD$

PORTNAME=	and
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Auto Nice Daemon

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
ALL_TARGET=	default
NOPRECIOUSMAKEVARS=	yes

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1100095
post-patch:
	@${REINPLACE_CMD} "s,P_KTHREAD,P_KPROC,g" \
		${WRKSRC}/Makefile ${WRKSRC}/and-OpenBSD.c
.endif

.include <bsd.port.post.mk>
