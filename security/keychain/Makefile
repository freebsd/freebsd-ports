# New ports collection makefile for:	keychain
# Date created:		10 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	keychain
PORTVERSION=	1.9
CATEGORIES=	security
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/distributions/gentoo/distfiles/ \
		ftp://sunsite.dk/mirrors/gentoo/distfiles/ \
		ftp://ftp.gtlib.cc.gatech.edu/pub/gentoo/distfiles/ \
		ftp://ftp.gentoo.no/pub/linux/distributions/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org

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
