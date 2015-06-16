# $FreeBSD$

PORTNAME=	acpica
PORTVERSION=	20150616
CATEGORIES=	sysutils devel
MASTER_SITES=	https://acpica.org/sites/acpica/files/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTNAME}-unix2-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Tools from the ACPI Component Architecture (ACPICA) project

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USES=		bison gmake

ACPICA_TOOLS=	acpibin acpidump acpiexec acpihelp acpinames acpisrc
ACPICA_TOOLS+=	acpixtract iasl

PLIST_FILES=	${ACPICA_TOOLS:S,^,bin/,}
WRKSRC_SUBDIR=	generate/unix

MAKE_ARGS=	HOST=_FreeBSD NOOPT=TRUE PROGS="${ACPICA_TOOLS}"
MAKE_ARGS+=	CC="${CC}" LEX="${FLEX}" MACROPROC="${LOCALBASE}/bin/gm4"
MAKE_ARGS+=	YACC="${LOCALBASE}/bin/bison"

do-install:
	${INSTALL_PROGRAM} ${ACPICA_TOOLS:S,^,${WRKSRC}/bin/,} \
	    ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
