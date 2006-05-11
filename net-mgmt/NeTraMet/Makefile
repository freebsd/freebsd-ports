# New ports collection makefile for:	NeTraMet
# Date created:		24-Feb-2001
# Whom:			Jimmy Olgeni <olgeni@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	NeTraMet
PORTVERSION=	4.4
PORTREVISION=	3
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.auckland.ac.nz/pub/iawg/NeTraMet/ \
		http://www2.auckland.ac.nz/net/Accounting/
DISTFILES+=	NeTraMet${PORTVERSION:S/.//}${EXTRACT_SUFX} \
		${NETRAMET_DOCS}
DIST_SUBDIR=	netramet
EXTRACT_ONLY=	NeTraMet${PORTVERSION:S/.//}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Implementation of the Internet Accounting Architecture

NETRAMET_DOCS=	usguide.pdf srlguide.pdf ntmref.pdf nm_rc.pdf \
		nifty.pdf fdutil.pdf

WRKSRC=		${WRKDIR}/NeTraMet${PORTVERSION:S/.//}

USE_AUTOTOOLS=	autoconf:213
USE_GMAKE=	yes

.if defined(WITH_MOTIF)
USE_MOTIF=	yes
CONFIGURE_ENV+=	MOTIF_LIB="${MOTIFLIB}"
PLIST_SUB=	MOTIF=""
.else
PLIST_SUB=	MOTIF="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|"/etc/mib.txt"|${LOCALBASE}/share/NeTraMet/mibs/mib.txt|g;" ${WRKSRC}/src/snmplib/mib.c

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${NETRAMET_DOCS}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
