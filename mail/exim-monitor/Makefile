# New ports collection makefile for:	exim-monitor
# Date created:		27 August 2001
# Whom:			sheldonh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	exim-monitor
PORTVERSION=	${EXIM_VERSION}
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_EXIM}
MASTER_SITE_SUBDIR=	exim4
DISTNAME=	exim-${PORTVERSION}
DIST_SUBDIR=	exim

MAINTAINER=	sheldonh@FreeBSD.org
COMMENT=	The Exim monitor for the Exim MTA

USE_BZIP2=	yes
USE_PERL5=	yes
USE_XLIB=	yes

EXIM_VERSION=	4.20

# This dependency is disabled, because it prevents package users from
# using the exim-monitor package with any of the exim slave packages.
#
#RUN_DEPENDS=	${LOCALBASE}/sbin/exim:${PORTSDIR}/mail/exim

MAKE_ENV+=	OSTYPE=${OPSYS} ARCHTYPE=${MACHINE_ARCH}

SEDLIST=	-e 's,XX_PREFIX_XX,${PREFIX},'

do-configure:
	${MKDIR} ${WRKSRC}/Local
	${SED} ${SEDLIST} < ${WRKSRC}/src/EDITME > ${WRKSRC}/Local/Makefile
	${CP} ${WRKSRC}/exim_monitor/EDITME ${WRKSRC}/Local/eximon.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon.bin \
	    ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon \
	    ${PREFIX}/sbin/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
