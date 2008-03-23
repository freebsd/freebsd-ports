# ex:ts=8
# Ports collection makefile for: 	sgrep2
# Date created:			Oct 31, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sgrep2
PORTVERSION=	1.94a
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.cs.helsinki.fi/pub/Software/Local/Sgrep/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jkoshy
DISTNAME=	sgrep-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A `grep' for structured text like SGML and HTML

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}

CONFLICTS=	sgrep-0.*

MAN1=		sgrep.1

.include <bsd.port.mk>
