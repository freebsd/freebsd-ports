# Ports collection makefile for:  nullmailer
# Date created:			  Tue Jan 30 2001
# Whom:				  clive
#
# $FreeBSD$
#

PORTNAME=	nullmailer
# PORTVERSION=	1.00RC5
PORTVERSION=	1.00r5
CATEGORIES=	mail
MASTER_SITES=	http://www.em.ca/~bruceg/nullmailer/archive/%SUBDIR%/
# MASTER_SITE_SUBDIR=	${PORTVERSION}
MASTER_SITE_SUBDIR=	1.00RC5
DISTNAME=	${PORTNAME}-1.00RC5

MAINTAINER=	clive@FreeBSD.org

HAS_CONFIGURE=	yes
IS_INTERACTIVE=	yes
NO_PACKAGE=	yes

MAN1=	nullmailer-inject.1 sendmail.1
MAN7=	nullmailer.7
MAN8=	nullmailer-queue.8 nullmailer-send.8

pre-install:
	@PKG_PREFIX="${PREFIX}" ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	@cd ${WRKSRC} && make install && make install-root

post-install:
	@${INSTALL} -c files/nullmail.sh ${PREFIX}/etc/rc.d/
	@${INSTALL} -c files/remotes.sample ${PREFIX}/etc/nullmailer/
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's,%%PREFIX%%,${PREFIX},'

.include <bsd.port.mk>
