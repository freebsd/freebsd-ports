# Ports collection makefile for: gnugadu
# Date created:		23 dec 2001
# Whom: 		doc@lublin.t1.pl
#
# $FreeBSD$
#

PORTNAME=	gnugadu
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	polish net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ggadu
DISTNAME=	gg-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GaduGadu client for X11/GTK

USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
USE_SUBMAKE=	yes
GNU_CONFIGURE=	yes

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		TOUCH="${TOUCH}" \
		MKDIR="${MKDIR}" \
		CAT="${CAT}" \
		GNUGADU_OPTIONS="${GNUGADU_OPTIONS}" \
		REALCURDIR="${.CURDIR}"

pre-fetch:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/configure.gg

post-patch:
	@${REINPLACE_CMD} -e 's,GTK_ CFLAGS,GTK_CFLAGS,' \
		-e 's,CFLAGS =, CFLAGS += @GTK_CFLAGS@ ${PTHREAD_CFLAGS},' \
		-e 's,@GTK_LIBS@,@GTK_LIBS@ ${PTHREAD_LIBS},'\
		${WRKSRC}/Makefile.in \
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e 's,-O2,,' -e 's,gtk-config,${GTK_CONFIG},' \
		${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${PREFIX}/bin/gg

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.mk>
