# New ports collection makefile for:	dirvish
# Date created:				28 April 2005
# Whom:					Loren M. Lang
#
# $FreeBSD$
#

PORTNAME=	dirvish
PORTVERSION=	1.2.1
PORTREVISION=	1
CATEGORIES=	sysutils archivers
MASTER_SITES=	http://www.dirvish.org/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tarkhil@over.ru
COMMENT=	Network backup system based off of rsync

RUN_DEPENDS=	${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules \
		${SITE_PERL}/Time/Period.pm:${PORTSDIR}/devel/p5-Time-Period \
		rsync:${PORTSDIR}/net/rsync

MAN5=		dirvish.conf.5
MAN8=		dirvish.8 dirvish-expire.8 dirvish-locate.8 dirvish-runall.8

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USE_PERL5_RUN=	yes

MAN5=		dirvish.conf.5
MAN8=		dirvish.8 dirvish-expire.8 dirvish-locate.8  dirvish-runall.8

EXECUTABLES=	dirvish   dirvish-expire   dirvish-locate   dirvish-runall

do-patch:
	@${SED} -e 's:%%CONFDIR%%:${PREFIX}/etc/dirvish:' -e 's:%%PERL%%:${PERL5}:' \
		${FILESDIR}/header.pl > ${WRKDIR}/header.pl
.for _E in ${EXECUTABLES}
	@(cd ${WRKSRC} && ${CAT} ${WRKDIR}/header.pl ${_E}.pl loadconfig.pl \
		> ${_E} && ${CHMOD} 755 ${_E})
.endfor

do-install:
	${MKDIR} ${PREFIX}/etc/dirvish
.for _E in ${EXECUTABLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${_E} ${PREFIX}/sbin
.endfor
.for _M in ${MAN5}
	${INSTALL_MAN} ${WRKSRC}/${_M} ${PREFIX}/man/man5
.endfor
.for _M in ${MAN8}
	${INSTALL_MAN} ${WRKSRC}/${_M} ${PREFIX}/man/man8
.endfor
	${INSTALL_DATA} ${FILESDIR}/master.conf.dist ${PREFIX}/etc/dirvish
	${INSTALL_DATA} ${FILESDIR}/default.conf.dist ${PREFIX}/etc/dirvish

.include <bsd.port.mk>
