PORTNAME=	acpica
PORTVERSION=	20240827
CATEGORIES=	sysutils devel
MASTER_SITES=	https://github.com/user-attachments/files/16769900/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTNAME}-unix-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Tools from the ACPI Component Architecture (ACPICA) project
WWW=		https://www.intel.com/content/www/us/en/developer/topic-technology/open/acpica/overview.html

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual

USES=		gmake

BUILD_WRKSRC=	${WRKSRC}/generate/unix

ACPICA_TOOLS=	acpibin acpidump acpiexec acpihelp acpisrc
ACPICA_TOOLS+=	acpixtract iasl

PLIST_FILES=	${ACPICA_TOOLS:S,^,bin/,}

MAKE_ARGS=	HOST=_FreeBSD PROGS="${ACPICA_TOOLS}"
MAKE_ARGS+=	CC="${CC}" LEX="${FLEX}" YACC="${YACC}"

post-extract:
	cd ${WRKSRC}/source/include && ${MV} ACPIXF.H acpixf.h

do-install:
	${INSTALL_PROGRAM} ${ACPICA_TOOLS:S,^,${BUILD_WRKSRC}/bin/,} \
	    ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
