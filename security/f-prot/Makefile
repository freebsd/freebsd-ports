# New ports collection makefile for:	f-prot
# Date created:			4 June 2003
# Whom:				Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	f-prot
PORTVERSION=	4.4.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.i-scream.org/pub/ftp.f-prot.com/pub/bsd/ \
		http://ftp.i-scream.org/pub/ftp.f-prot.com/pub/bsd/
DISTNAME=	fp-freebsd-ws-${PORTVERSION}

MAINTAINER=	tim@bishnet.net
COMMENT=	F-Prot Antivirus for BSD Workstations

RUN_DEPENDS=	${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/f-prot/SIGN.DEF:${PORTSDIR}/security/f-prot-sig

NO_PACKAGE=	Free for personal use only
NO_CDROM=	Free for personal use only
RESTRICTED=	Free for personal use only

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

MAN1=		f-prot.1

ONLY_FOR_ARCHS=	i386

do-install:
	cd ${WRKDIR} && ${TAR}	--exclude man_pages \
				--exclude doc_ws \
				--exclude f-prot.sh \
				--exclude *.DEF \
				--exclude install-f-prot.pl \
				-cf - f-prot | ${TAR} -xf - -C ${PREFIX}

	${INSTALL_SCRIPT} ${WRKSRC}/f-prot.sh ${PREFIX}/bin/f-prot
	${INSTALL_MAN} ${WRKSRC}/man_pages/f-prot.1 ${MANPREFIX}/man/man1/
	${CHMOD} 755 ${PREFIX}/f-prot/tools/check-updates.pl

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -Rp ${WRKSRC}/doc_ws/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
