# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	tlb
PORTVERSION= 	0.11a
CATEGORIES=	mail perl5
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/tlb/ \
		http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	The List Batcher, a general purpose mail list delivery engine

RUN_DEPENDS=	p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-Net>=0:${PORTSDIR}/net/p5-Net

NO_BUILD=	yes
USE_PERL5=	yes

DOCS=	FAQ INSTALL README README.loglevels README.mungelist TIPS TODO \
	complete.tlb mj.tlb simple.tlb
FIXPREFIX=	tlb mungelist complete.tlb mj.tlb simple.tlb

USES=		shebangfix
SHEBANG_FILES=	${FIXPREFIX}
perl_OLD_CMD=	/usr/local/bin/perl5

pre-patch:
.for f in ${FIXPREFIX}
	@${PERL} -pi -e "s@/usr/lib/sendmail@/usr/sbin/sendmail@g" ${WRKSRC}/${f}
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
