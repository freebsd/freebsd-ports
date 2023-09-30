PORTNAME=	acpica
PORTVERSION=	20221020
CATEGORIES=	sysutils devel
MASTER_SITES=	https://acpica.org/sites/acpica/files/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTNAME}-unix-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Tools from the ACPI Component Architecture (ACPICA) project
WWW=		https://acpica.org

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual

USES=		gmake

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
