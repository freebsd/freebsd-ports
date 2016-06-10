# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	tlb
PORTVERSION=	0.11a
CATEGORIES=	mail perl5
MASTER_SITES=	ftp://ftp.hpc.uh.edu/pub/tlb/ \
		http://www.freenix.no/~anders/ \
		ftp://totem.fix.no/pub/mirrors/misc/ \
		http://ports.toco-domains.de/

MAINTAINER=	tz@FreeBSD.org
COMMENT=	The List Batcher, a general purpose mail list delivery engine

RUN_DEPENDS=	p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-Net>=0:net/p5-Net

NO_BUILD=	yes

DOCS=	FAQ INSTALL README README.loglevels README.mungelist TIPS TODO \
	complete.tlb mj.tlb simple.tlb
FIXPREFIX=	tlb mungelist complete.tlb mj.tlb simple.tlb

USES=		shebangfix perl5 tar:tgz
SHEBANG_FILES=	${FIXPREFIX}
perl_OLD_CMD=	/usr/local/bin/perl5

OPTIONS_DEFINE=	DOCS

pre-patch:
.for f in ${FIXPREFIX}
	@${REINPLACE_CMD} -i '' -e 's@/usr/lib/sendmail@/usr/sbin/sendmail@' ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tlb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mungelist ${STAGEDIR}${PREFIX}/bin

	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
