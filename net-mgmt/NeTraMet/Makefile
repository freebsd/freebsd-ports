# New ports collection makefile for:	NeTraMet
# Date created:		24-Feb-2001
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	NeTraMet
PORTVERSION=	4.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.gla.ac.uk/pub/software/NeTraMet/
DISTNAME=	NeTraMet${PORTVERSION:S/.//}

MAINTAINER=	olgeni@FreeBSD.org

WRKSRC=		${WRKDIR}/NeTraMet${PORTVERSION:S/.//}

USE_REINPLACE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes

.if defined(WITH_MOTIF)
USE_MOTIF=	yes
CONFIGURE_ENV+=	MOTIF_LIB="${MOTIFLIB}"
PLIST_SUB=	MOTIF=""
.else
PLIST_SUB=	MOTIF="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e "s|"/etc/mib.txt"|${LOCALBASE}/share/NeTraMet/mibs/mib.txt|g;" ${WRKSRC}/src/snmplib/mib.c

.include <bsd.port.mk>
