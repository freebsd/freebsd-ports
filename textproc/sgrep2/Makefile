# ex:ts=8
# Ports collection makefile for: 	sgrep2
# Date created:			Oct 31, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sgrep2
PORTVERSION=	1.92a
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.helsinki.fi/pub/Software/Local/Sgrep/
DISTNAME=	sgrep-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A `grep' for structured text like SGML and HTML

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}

CONFLICT=	sgrep

MAN1=		sgrep.1

.include <bsd.port.mk>
