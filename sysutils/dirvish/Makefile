# Created by: Loren M. Lang
# $FreeBSD$

PORTNAME=	dirvish
PORTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	sysutils archivers
MASTER_SITES=	http://www.dirvish.org/

MAINTAINER=	tarkhil@over.ru
COMMENT=	Network backup system based off of rsync

RUN_DEPENDS=	p5-Time-modules>=0:devel/p5-Time-modules \
		p5-Time-Period>=0:devel/p5-Time-Period \
		rsync:net/rsync

MAN5S=		dirvish.conf.5
MAN8S=		dirvish.8 dirvish-expire.8 dirvish-locate.8 dirvish-runall.8

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
USES=		perl5 tar:tgz
USE_PERL5=	run

EXECUTABLES=	dirvish   dirvish-expire   dirvish-locate   dirvish-runall

do-patch:
	@${SED} -e 's:%%CONFDIR%%:${PREFIX}/etc/dirvish:' -e 's:%%PERL%%:${PERL}:' \
		${FILESDIR}/header.pl > ${WRKDIR}/header.pl
.for _E in ${EXECUTABLES}
	@(cd ${WRKSRC} && ${CAT} ${WRKDIR}/header.pl ${_E}.pl loadconfig.pl \
		> ${_E})
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/dirvish
.for _E in ${EXECUTABLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${_E} ${STAGEDIR}${PREFIX}/sbin
.endfor
.for _M in ${MAN5S}
	${INSTALL_MAN} ${WRKSRC}/${_M} ${STAGEDIR}${PREFIX}/man/man5
.endfor
.for _M in ${MAN8S}
	${INSTALL_MAN} ${WRKSRC}/${_M} ${STAGEDIR}${PREFIX}/man/man8
.endfor
	${INSTALL_DATA} ${FILESDIR}/master.conf.dist ${STAGEDIR}${PREFIX}/etc/dirvish
	${INSTALL_DATA} ${FILESDIR}/default.conf.dist ${STAGEDIR}${PREFIX}/etc/dirvish

.include <bsd.port.mk>
