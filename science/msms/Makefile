# $FreeBSD$

PORTNAME=	msms
DISTVERSION=	2.6.1
CATEGORIES=	science
MASTER_SITES=	http://mgltools.scripps.edu/downloads/tars/releases/MSMSRELEASE/REL${DISTVERSION}/
DISTNAME=	${PORTNAME}_${ARCH_MSMS_DIST}Linux2_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Program to efficiently compute molecular surfaces

LICENSE=	MSMS_LICENSE
LICENSE_NAME=	MSMS License
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	none # No redistribution is allowed, no commercial use, only for use by individuals

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	Binaries available only for ${ONLY_FOR_ARCHS}.

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ARCH_MSMS_DIST=	${ARCH:S/amd64/i86_64/:S/i386/i86/}
ARCH_MSMS_FILE=	${ARCH:S/amd64/x86_64/:S/i386/i86/}

DISTINFO_FILE=	${MASTERDIR}/distinfo-${ARCH}

PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

post-extract:
	@${AWK} -f ${FILESDIR}/extract-license.awk < ${WRKSRC}/README > ${LICENSE_FILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME}.${ARCH_MSMS_FILE}Linux2.${DISTVERSION}${ARCH:S/amd64/.staticgcc/:S/${ARCH}//} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
