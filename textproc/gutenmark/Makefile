# ex:ts=8
# Ports collection makefile for:	GutenMark
# Date created:			Jun 7, 2002
# Whom:				ijliao
#
# $FreeBSD$

PORTNAME=	gutenmark
PORTVERSION=	20011228
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.sandroid.org/GutenMark/SoftwareSnapshots/
DISTNAME=	GutenMark_source_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/GutenMark-source
USE_GMAKE=	yes
ALL_TARGET=	# empty

post-patch:
	@${PERL} -pi -e "s,cc,${CC},g ; s,-O3 -Wall,${CFLAGS},g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GutenMark ${PREFIX}/bin

.include <bsd.port.mk>
