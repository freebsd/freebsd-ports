# New ports collection makefile for:	tlb
# Date created:			01 July 2001
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	tlb
PORTVERSION= 	0.11a
CATEGORIES=	mail perl5
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/tlb/ \
		http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	The List Batcher, a general purpose mail list delivery engine

RUN_DEPENDS=	${SITE_PERL}/Mail/Address.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/Date/Format.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/Net/Domain.pm:${PORTSDIR}/net/p5-Net

NO_BUILD=	yes
USE_PERL5=	yes

DOCS=	FAQ INSTALL README README.loglevels README.mungelist TIPS TODO \
	complete.tlb mj.tlb simple.tlb
FIXPREFIX=	tlb mungelist complete.tlb mj.tlb simple.tlb

pre-patch:
.for f in ${FIXPREFIX}
	${PERL} -pi -e "s@^#!/usr/local/bin/perl5@#!${PERL}@g;\
		s@/usr/lib/sendmail@/usr/sbin/sendmail@g" ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tlb ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mungelist ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/share/doc/tlb
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/tlb
.endfor
.endif

.include <bsd.port.mk>
