# New ports collection makefile for:    wais
# Version required:     0.5
# Date created:         20 Sep 1994
# Whom:                 adam
#
# $Id: Makefile,v 1.11 1996/12/01 01:23:17 obrien Exp $
#

DISTNAME=       freeWAIS-0.5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cnidr.org/pub/NIDR.tools/freewais/

MAINTAINER=	ports@FreeBSD.org

NO_PACKAGE=	"not yet"
NO_INSTALL=	almost
ALL_TARGET=	freebsd
MAKE_ENV:=	TOP=${WRKSRC}

is_depended: all

pre-patch:
	@${CP} ${WRKSRC}/Makefile.bsdi ${WRKSRC}/Makefile.freebsd
	@mv ${WRKSRC}/src/client/x/Imakefile ${WRKDIR} \
	&& ${SED} -e '\;/SETME_IN_Imakefile;s;;${WRKSRC};' \
		<${WRKDIR}/Imakefile >${WRKSRC}/src/client/x/Imakefile

.if ${MAKEFILE} != Makefile.freebsd
do-install:
	${MAKE} MAKEFILE=Makefile.freebsd do-install
.endif

.include <bsd.port.mk>
