# New ports collection makefile for:	ppp + nat + time schedule
# Version required:	2.2.7
# Date created:		10 August 1998
# Whom:			SADA Kenji <sada@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/11/23 08:38:25 asami Exp $
#

DISTNAME=	ppp-2.2.7
PKGNAME=	ppp-nt-2.2.7
CATEGORIES=	net
MASTER_SITES=	http://www.jp.freebsd.org/~sada/distfiles/ \
		http://www.freebsd.org/~sada/distfiles/

PATCH_SITES=	http://www2a.meshnet.or.jp/~junichi/freebsd/programs/ \
		http://www.rr.iij4u.or.jp/~sada/patches/ \
		http://www.freebsd.org/~sada/distfiles/
PATCHFILES=	nat-980920.patch ppp-2.2.7-telehoudai.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sada@FreeBSD.ORG

MANCOMPRESSED=	yes
MAN8=		ppp.8
WRKSRC=		${WRKDIR}/ppp
MAKE_ENV=	USE_SCHEDULE=YES

.SILENT:

do-configure:
.for i in Makefile
	${MV} -f ${WRKSRC}/${i} ${WRKSRC}/${i}.in
	${SED} -e "s;@PREFIX@;${PREFIX};g" ${WRKSRC}/${i}.in >${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
