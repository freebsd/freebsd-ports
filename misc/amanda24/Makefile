# New ports collection makefile for:	amanda
# Version required:			2.3.0
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $Id: Makefile,v 1.20 1998/09/13 01:16:01 cwt Exp $
#

DISTNAME=	amanda-2.4.1p1
PKGNAME=	amanda-2.4.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.amanda.org/pub/amanda/

MAINTAINER=	cwt@FreeBSD.ORG

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

WRKSRC=		${WRKDIR}/amanda-2.4.1p1
NO_LATEST_LINK=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump \
		--with-user=operator --with-group=operator

PATCH_STRIP=
MAN8=		amadmin.8 amanda.8 amcheck.8 amcheckdb.8 amcleanup.8 \
		amdump.8 amflush.8 amlabel.8 amoverview.8 amplot.8 \
		amrecover.8 amreport.8 amrestore.8 amrmtape.8 amstatus.8 \
		amtape.8 amtoc.8 amverify.8

post-install:
	${MKDIR} ${PREFIX}/share/examples/amanda
	${CP} -R ${WRKSRC}/example/amanda.conf \
		${WRKSRC}/example/chg-multi.conf \
		${WRKSRC}/example/chg-scsi.conf \
		${WRKSRC}/example/disklist \
		${PREFIX}/share/examples/amanda

.include <bsd.port.mk>
