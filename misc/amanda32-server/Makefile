# New ports collection makefile for:	amanda
# Date created:				28th Feb 1995
# Whom:					gpalmer
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	2.4.2
PORTREVISION?=	0
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.amanda.org/pub/amanda/
DISTFILES=	amanda-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	jeh@FreeBSD.org

WRKSRC=		${WRKDIR}/amanda-${PORTVERSION}
SLAVEDIRS=	misc/amanda24-client
MASTERPORTNAME=	amanda24-server

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
LIBTOOLFLAGS=	--disable-ltlibs --release-ignore
PATCH_STRIP=

.include <bsd.port.pre.mk>
# amanda24-server part
.if !defined(CLIENT_ONLY)

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "    -DWITH_PLOT to enable ploting, requires X11 libraries"
	@${ECHO} "    -DWITH_SAMBA to enable the use of smbclient"
	@${ECHO} ""

RUN_DEPENDS=	amrecover:${.CURDIR}/../amanda24-client
BUILD_DEPENDS=	amrecover:${.CURDIR}/../amanda24-client
#RUN_DEPENDS=	amrecover:${PORTSDIR}/misc/amanda24-client
#BUILD_DEPENDS=	amrecover:${PORTSDIR}/misc/amanda24-client

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--with-user=operator --with-group=operator \
		--without-client

MAN8=		amadmin.8 amcheck.8 amcheckdb.8 amcleanup.8 amdump.8 \
		amflush.8 amgetconf.8 amlabel.8 amoverview.8 amreport.8 \
		amrmtape.8 amstatus.8 amtape.8 amtoc.8 amverify.8

.if defined (WITH_PLOT)
BUILD_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
MAN8+=		amplot.8
PLIST_SUB+=	PLOT=''
.else
PLIST_SUB+=	PLOT='@comment '
.endif

.if defined (WITH_SMBCLIENT)
BUILD_DEPEND+=	smbclient:${PORTSDIR}/net/samba
RUN_DEPEND+=	smbclient:${PORTSDIR}/net/samba
CONFIGURE_ARGS+=	--with-smbclient=${PREFIX}/bin/smbclient
.endif

# amanda24-client part
.else

CONFIGURE_ARGS=	--libexecdir=${PREFIX}/libexec/amanda \
		--with-amandahosts --with-fqdn \
		--with-dump-honor-nodump --with-buffered-dump \
		--with-user=operator --with-group=operator \
		--without-server

MAN8=		amanda.8 amrecover.8 amrestore.8

post-install:
	${MKDIR} ${PREFIX}/share/examples/amanda
	${CP} -R ${WRKSRC}/example/amanda.conf \
		${WRKSRC}/example/chg-multi.conf \
		${WRKSRC}/example/chg-scsi.conf \
		${WRKSRC}/example/disklist \
		${PREFIX}/share/examples/amanda

.endif

.include <bsd.port.post.mk>
