# New ports collection makefile for:	ranlib
# Version required:	?
# Date created:		06 April 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1997/04/23 06:57:54 tg Exp $
#

DISTNAME=	ranlib.c
PKGNAME=	ranlib-1.0
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.netlib.org/random/

MAINTAINER=	tg@FreeBSD.ORG

WRKSRC=		${WRKDIR}/${DISTNAME}/src

post-extract:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ranlib
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/* ${PREFIX}/share/doc/ranlib
.endif
	if [ "${PORTOBJFORMAT}" = "aout" ]; then \
		${LN} -sf libranlib.so.1.0 ${PREFIX}/lib/libranlib.so; \
	fi
	@${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
