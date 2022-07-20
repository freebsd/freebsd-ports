PORTNAME=	f-prot
PORTVERSION=	6.5.1.5927
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://ftp.i-scream.org/pub/ftp.f-prot.com/pub/bsd/
DISTNAME=	fp-FreeBSD-x86_32-ws-${PORTVERSION}

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	F-Prot Antivirus for BSD Workstations

# Converted from RESTRICTED
LICENSE=	f-prot-license
LICENSE_NAME=	f-prot
LICENSE_TEXT=	Free for personal users on personal workstations only
LICENSE_PERMS=	auto-accept

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes
SUB_FILES=	900.fpupdate fpscan fpupdate

OPTIONS_DEFINE=	DOCS

ONLY_FOR_ARCHS=	i386 amd64

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/fpscan ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/fpupdate ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/antivir.def ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/license.key ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/product.data ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/libexec/${PORTNAME}

	${INSTALL_DATA} ${WRKSRC}/f-prot.conf.default ${STAGEDIR}${PREFIX}/etc/f-prot.conf.sample

	${INSTALL_SCRIPT} ${WRKDIR}/fpscan ${STAGEDIR}${PREFIX}/bin/fpscan
	${INSTALL_SCRIPT} ${WRKDIR}/fpupdate ${STAGEDIR}${PREFIX}/bin/fpupdate

	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/900.fpupdate ${STAGEDIR}${PREFIX}/etc/periodic/daily

	${INSTALL_MAN} ${WRKSRC}/doc/man/fpscan.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/man/f-prot.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/man/fpupdate.8 ${STAGEDIR}${MANPREFIX}/man/man8

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} html ${STAGEDIR}${DOCSDIR})
	${CP} ${WRKSRC}/doc/CHANGES ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/LICENSE ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/LICENSE-FPAV ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/doc/LICENSES-others ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
