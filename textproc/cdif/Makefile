# New ports collection makefile for:	cdif
# Date created:		July 22, 2000
# Whom:			Yoshiro MIHIRA <sanpei@sanpei.org>
#
# $NetBSD: Makefile,v 1.2 2000/03/16 14:08:38 wiz Exp $
# $FreeBSD$
#

PORTNAME=		cdif
PORTVERSION=		1.15
CATEGORIES=		textproc
MASTER_SITES=		ftp://ftp.iij.ad.jp/pub/IIJ/dist/utashiro/perl/
EXTRACT_SUFX=		# empty

MAINTAINER=		sanpei@FreeBSD.org

USE_PERL5=		yes

NO_WRKSUBDIR=		yes
NO_BUILD=		yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${DISTNAME}.dist

# assumes perl is in ${LOCALBASE}/bin/perl
do-patch:
	${SED} -e '1s@/usr/local/bin/perl@${LOCALBASE}/bin/perl@' \
		< ${WRKSRC}/${DISTNAME}.dist > ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/cdif

.include <bsd.port.mk>
