# Ports collection makefile for:  uucp
# Date created:			  08 Sep 2001
# Whom:				  Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freebsd-uucp
PORTVERSION=	1.06.1.2
CATEGORIES=	net comms
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=dinoex

MAINTAINER=	lyndon@atg.aciworldwide.com

USE_BZIP2=	yes

MAN1=	cu.1 uuconv.1 uucp.1 uulog.1 uuname.1 uupick.1 uustat.1 \
	uuto.1 uux.1
MAN8=	uuchk.8 uucico.8 uusched.8 uuxqt.8 uucpd.8
MANCOMPRESSED=	maybe

post-extract:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} configure)

post-install:
	@${ECHO} "Use the 'make upgrade' command to copy your old configuration"
	@${ECHO} "files from /etc/uucp to the new location in ${PREFIX}/etc/uucp"
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

upgrade:
	@${ECHO} "Copying old configuration files from /etc/uucp to ${PREFIX}/etc/uucp"
	@${CP} -rp /etc/uucp ${PREFIX}/etc/uucp

.include <bsd.port.mk>
