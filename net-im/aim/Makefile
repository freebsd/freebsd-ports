# New ports collection makefile for:	aim
# Date created:		Sat Jan 13 12:40:20 GMT 2001
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	aim
PORTVERSION=	1.5.286
PORTREVISION=	4
CATEGORIES=	net-im linux
MASTER_SITES=	ftp://ftp.newaol.com/aimgen/380469/
DISTNAME=	aim-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AOL's Instant Messenger (AIM) client

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	yes
USE_LINUX_APPS=	gtk xorglibs
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_LDCONFIG=	yes
USE_LINUX_PREFIX=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/aim ${LINUXBASE}/usr/bin
	${BRANDELF} -t Linux ${LINUXBASE}/usr/bin/aim
	(cd ${WRKSRC}/usr/lib;exec ${TAR} --exclude aim/source -cf - *)|(cd ${LINUXBASE}/usr/lib;exec ${TAR} -xpf -)
	@${ECHO_CMD} "#!/bin/sh" >${PREFIX}/bin/aim
	@${ECHO_CMD} "ulimit -Sc 0" >>${PREFIX}/bin/aim
	@${ECHO_CMD} -n "exec ${LINUXBASE}/usr/bin/aim" >>${PREFIX}/bin/aim
	@${ECHO_CMD} ' "$$@"' >>${PREFIX}/bin/aim
	${CHMOD} ${BINMODE} ${PREFIX}/bin/aim

.include <bsd.port.pre.mk>

post-install:
.if !exists(${LINUXBASE}/usr/bin/esdplay) && !exists(${LOCALBASE}/bin/esdplay)
	@${ECHO_MSG} "-----------------------------------------------------------------"
	@${ECHO_MSG} "Install audio/linux-esound or disable Sounds in aim's Preferences"
	@${ECHO_MSG} "-----------------------------------------------------------------"
.endif

.include <bsd.port.post.mk>
