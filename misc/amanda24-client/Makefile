# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME=	amanda
PORTVERSION=	2.4.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.amanda.org/pub/amanda/
DISTNAME=	amanda-2.4.1p1

MAINTAINER=	cwt@FreeBSD.org

BUILD_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS=	gnuplot:${PORTSDIR}/math/gnuplot

WRKSRC=		${WRKDIR}/amanda-2.4.1p1
NO_LATEST_LINK=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIBS=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
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
