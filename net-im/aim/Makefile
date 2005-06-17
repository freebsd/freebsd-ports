# New ports collection makefile for:	aim
# Date created:		Sat Jan 13 12:40:20 GMT 2001
# Whom:			Roger Hardiman <roger@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	aim
PORTVERSION=	1.5.286
PORTREVISION=	2
CATEGORIES=	net linux
MASTER_SITES=	ftp://ftp.newaol.com/aimgen/380469/
DISTNAME=	aim-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	AOL's Instant Messenger (AIM) client

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/bin/aim ${PREFIX}/libexec
	${BRANDELF} -t Linux ${PREFIX}/libexec/aim
	(cd ${WRKSRC}/usr/lib;exec ${TAR} --exclude aim/source -cf - *)|(cd ${PREFIX}/lib;exec ${TAR} -xpf -)
	@${ECHO_CMD} "#!/bin/sh" >${PREFIX}/bin/aim
	@${ECHO_CMD} "ulimit -Sc 0" >>${PREFIX}/bin/aim
	@${ECHO_CMD} -n "exec ${PREFIX}/libexec/aim --install_dir ${PREFIX}/lib/aim" >>${PREFIX}/bin/aim
	@${ECHO_CMD} ' "$$@"' >>${PREFIX}/bin/aim
	${CHMOD} ${BINMODE} ${PREFIX}/bin/aim

post-install:
.if !exists(${LINUXBASE}/usr/bin/esdplay) && !exists(${PREFIX}/bin/esdplay)
	@${ECHO_MSG} "-----------------------------------------------------------------"
	@${ECHO_MSG} "Install audio/linux-esound or disable Sounds in aim's Preferences"
	@${ECHO_MSG} "-----------------------------------------------------------------"
.endif

.include <bsd.port.mk>
