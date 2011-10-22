# New ports collection makefile for:	f-prot
# Date created:			4 June 2003
# Whom:				Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	f-prot
PORTVERSION=	6.5.1.5927
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.i-scream.org/pub/ftp.f-prot.com/pub/bsd/ \
		http://ftp.i-scream.org/pub/ftp.f-prot.com/pub/bsd/
DISTNAME=	fp-FreeBSD-x86_32-ws-${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	F-Prot Antivirus for BSD Workstations

RESTRICTED=	Free for personal users on personal workstations only

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	900.fpupdate fpscan fpupdate

MAN1=		fpscan.1
MAN5=		f-prot.conf.5
MAN8=		fpupdate.8

ONLY_FOR_ARCHS=	i386 amd64

do-install:
	${MKDIR} ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/fpscan ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/fpupdate ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/antivir.def ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/license.key ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/product.data ${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/libexec/${PORTNAME}

	${INSTALL_DATA} ${WRKSRC}/f-prot.conf.default ${PREFIX}/etc/f-prot.conf.sample

	${INSTALL_SCRIPT} ${WRKDIR}/fpscan ${PREFIX}/bin/fpscan
	${INSTALL_SCRIPT} ${WRKDIR}/fpupdate ${PREFIX}/bin/fpupdate

	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/900.fpupdate ${PREFIX}/etc/periodic/daily

	${INSTALL_MAN} ${WRKSRC}/doc/man/fpscan.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN} ${WRKSRC}/doc/man/f-prot.conf.5 ${MANPREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/doc/man/fpupdate.8 ${MANPREFIX}/man/man8/

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/html ${DOCSDIR}
	${CP} ${WRKSRC}/doc/CHANGES ${DOCSDIR}
	${CP} ${WRKSRC}/doc/LICENSE ${DOCSDIR}
	${CP} ${WRKSRC}/doc/LICENSE-FPAV ${DOCSDIR}
	${CP} ${WRKSRC}/doc/LICENSES-others ${DOCSDIR}
.endif
	@if [ ! -f ${PREFIX}/etc/f-prot.conf ]; then \
		${CP} -p ${PREFIX}/etc/f-prot.conf.sample ${PREFIX}/etc/f-prot.conf ; \
	fi
	@if [ ! -e /etc/f-prot.conf ]; then \
		${LN} -s ${PREFIX}/etc/f-prot.conf /etc/f-prot.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
