# ex:ts=8
# Ports collection makefile for:	GutenMark
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	gutenmark
PORTVERSION=	20020714
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.sandroid.org/GutenMark/SoftwareSnapshots/
DISTNAME=	GutenMark_source_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Attractively formatting Project Gutenberg texts

USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/GutenMark-source
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-patch:
	@${REINPLACE_CMD} -e "s,cc,${CC},g" \
		-e "s,-O3 -Wall,${CFLAGS},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GutenMark ${PREFIX}/bin

.include <bsd.port.mk>
