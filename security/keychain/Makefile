# New ports collection makefile for:	keychain
# Date created:		10 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	keychain
PORTVERSION=	1.7
CATEGORIES=	security
MASTER_SITES=	http://www.ibiblio.org/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	pidof:${PORTSDIR}/sysutils/psmisc

USE_BZIP2=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400016
RUN_DEPENDS=	ssh-agent:${PORTSDIR}/security/openssh
.endif

do-install:
	@ ${MKDIR} ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>
