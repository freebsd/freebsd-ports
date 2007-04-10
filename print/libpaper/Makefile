# New ports collection makefile for:    libpaper
# Date created:         Do 16 Nov 2003 20:00:00 CET
# Whom:                 lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libpaper
PORTVERSION=	1.1.21
PORTREVISION=	0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/libp/libpaper
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	lofi@freebsd.org
COMMENT=	A library providing routines for paper size management

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--build=${CONFIGURE_TARGET} --mandir=${PREFIX}/man

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=	paperconf.1
MAN3=	defaultpapername.3 defaultpapersizefile.3 paperdone.3 paperfirst.3 \
	paperinfo.3 paperinit.3 paperlast.3 papernext.3 paperprev.3 \
	paperpsheight.3 paperpsname.3 paperpswidth.3 paperwithsize.3 \
	systempapername.3 systempapersizefile.3
MAN5=	papersize.5
MAN8=	paperconfig.8

pre-configure:
	@${TOUCH} ${WRKSRC}/config.sub

post-configure:
	@${REINPLACE_CMD} -e 's|$${prefix}|${PREFIX}|g' ${WRKSRC}/config.h

.include <bsd.port.mk>
