# New ports collection makefile for:    wais
# Date created:         20 Sep 1994
# Whom:                 adam
#
# $FreeBSD$
#

PORTNAME=	freeWAIS
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cnidr.org/software/freewais/ \
		ftp://ftp.icm.edu.pl/vol/wojsyl/freewais/ \
		ftp://ftp.bio.indiana.edu/util/wais/ \
		ftp://ftp.imb-jena.de/software/unix/net/ \
		ftp://ftp.amu.edu.pl/unix/network/ \
		ftp://ftp.gu.net/pub/unix/wais/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/comm/infosystems/wais/ \
		ftp://ftp.cuhk.edu.hk/pub/unix/ \
		ftp://ftp.uni-koeln.de/net/inet/wais/freeWAIS-sf-old/ \
		ftp://ftp.netsw.org/infosys/wais/freewais/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Wide Area Information Server

NO_PACKAGE=	"not yet"
NO_INSTALL=	almost
ALL_TARGET=	freebsd
MAKE_ENV:=	TOP=${WRKSRC}

is_depended: all

pre-patch:
	@${CP} ${WRKSRC}/Makefile.bsdi ${WRKSRC}/Makefile.freebsd
	@${MV} ${WRKSRC}/src/client/x/Imakefile ${WRKDIR} \
	&& ${SED} -e '\;/SETME_IN_Imakefile;s;;${WRKSRC};' \
		<${WRKDIR}/Imakefile >${WRKSRC}/src/client/x/Imakefile

.if ${MAKEFILE} != Makefile.freebsd
do-install:
	${MAKE} MAKEFILE=Makefile.freebsd do-install
.endif

.include <bsd.port.mk>
