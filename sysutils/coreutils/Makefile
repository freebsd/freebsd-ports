# New ports collection makefile for:	coreutils
# Date created:				18 November 2003
# Whom:					Jason Harris <jharris@widomaker.com>
#
# $FreeBSD$
#

PORTNAME=	coreutils
PORTVERSION=	5.2.1
CATEGORIES=	sysutils textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.sig
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jharris@widomaker.com
COMMENT=	The Free Software Foundation's core utilities

CONFLICTS=	fileutils-[0-9]* id-utils-[0-9]* linux-gid-[0-9]* \
		sh-utils-[0-9]*  textutils-[0-9]*

USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.sig
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

USE_GMAKE=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

INFO=		coreutils

MAN1=	gbasename.1 gcat.1 gchgrp.1 gchmod.1 gchown.1 gchroot.1 gcksum.1 \
	gcomm.1 gcp.1 gcsplit.1 gcut.1 gdate.1 gdd.1 gdf.1 gdir.1 \
	gdircolors.1 gdirname.1 gdu.1 gecho.1 genv.1 gexpand.1 gexpr.1 \
	gfactor.1 gfalse.1 gfmt.1 gfold.1 ggroups.1 ghead.1 ghostid.1 \
	ghostname.1 gid.1 ginstall.1 gjoin.1 gkill.1 glink.1 gln.1 \
	glogname.1 gls.1 gmd5sum.1 gmkdir.1 gmkfifo.1 gmknod.1 gmv.1 \
	gnice.1 gnl.1 gnohup.1 god.1 gpaste.1 gpathchk.1 gpinky.1 \
	gpr.1 gprintenv.1 gprintf.1 gptx.1 gpwd.1 greadlink.1 grm.1 \
	grmdir.1 gseq.1 gsha1sum.1 gshred.1 gsleep.1 gsort.1 gsplit.1 \
	gstat.1 gstty.1 gsu.1 gsum.1 gsync.1 gtac.1 gtail.1 gtee.1 \
	gtest.1 gtouch.1 gtr.1 gtrue.1 gtsort.1 gtty.1 guname.1 \
	gunexpand.1 guniq.1 gunlink.1 guptime.1 gusers.1 gvdir.1 \
	gwc.1 gwho.1 gwhoami.1 gyes.1

post-patch:
.if !defined(WITH_SUID)
	@${REINPLACE_CMD} -e "s/u\+s/u\+w/g" ${WRKSRC}/src/Makefile.in
.endif

post-build:
	@${REINPLACE_CMD} -e "s/ lib / /g" ${WRKSRC}/Makefile

post-install:

.include <bsd.port.mk>
