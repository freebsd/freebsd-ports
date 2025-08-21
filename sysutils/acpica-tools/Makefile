PORTNAME=	acpica
PORTVERSION=	20250807
CATEGORIES=	sysutils devel
PKGNAMESUFFIX=	-tools

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Tools from the ACPI Component Architecture (ACPICA) project
WWW=		https://www.intel.com/content/www/us/en/developer/topic-technology/open/acpica/overview.html

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual

USES=		gmake
USE_GITHUB=	yes

BUILD_WRKSRC=	${WRKSRC}/generate/unix

ACPICA_TOOLS=	acpibin acpidump acpiexec acpihelp acpisrc
ACPICA_TOOLS+=	acpixtract iasl

PLIST_FILES=	${ACPICA_TOOLS:S,^,bin/,}

MAKE_ARGS=	HOST=_FreeBSD PROGS="${ACPICA_TOOLS}"
MAKE_ARGS+=	CC="${CC}" LEX="${FLEX}" YACC="${YACC}"

do-install:
	${INSTALL_PROGRAM} ${ACPICA_TOOLS:S,^,${BUILD_WRKSRC}/bin/,} \
	    ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
