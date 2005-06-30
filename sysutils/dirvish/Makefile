# New ports collection makefile for:	dirvish
# Date created:				28 April 2005
# Whom:					Loren M. Lang
#
# $FreeBSD$
#

PORTNAME=	dirvish
PORTVERSION=	1.2.1
CATEGORIES=	sysutils archivers
MASTER_SITES=	http://www.dirvish.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lorenl@alzatex.com
COMMENT=	Network backup system based off of rsync

RUN_DEPENDS=	${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/Time/Period.pm:${PORTSDIR}/devel/p5-Time-Period \
		rsync:${PORTSDIR}/net/rsync

MAN5=		dirvish.conf.5
MAN8=		dirvish.8 dirvish-expire.8 dirvish-locate.8 dirvish-runall.8

NO_BUILD=	yes
USE_PERL5_RUN=	yes

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SH} install.sh < /dev/null)
	${MKDIR} ${PREFIX}/etc/dirvish
	${INSTALL_DATA} ${FILESDIR}/master.conf.dist ${PREFIX}/etc/dirvish
	${INSTALL_DATA} ${FILESDIR}/default.conf.dist ${PREFIX}/etc/dirvish

.include <bsd.port.mk>
