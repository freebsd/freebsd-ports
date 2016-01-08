# $FreeBSD$

PORTNAME=	acpica
PORTVERSION=	20160108
CATEGORIES=	sysutils devel
MASTER_SITES=	https://acpica.org/sites/acpica/files/ \
		LOCAL/jkim
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTNAME}-unix2-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Tools from the ACPI Component Architecture (ACPICA) project

LICENSE=	BSD3CLAUSE GPLv2
LICENSE_COMB=	dual

USES=		gmake

BUILD_WRKSRC=	${WRKSRC}/generate/unix

ACPICA_TOOLS=	acpibin acpidump acpiexec acpihelp acpinames acpisrc
ACPICA_TOOLS+=	acpixtract iasl

PLIST_FILES=	${ACPICA_TOOLS:S,^,bin/,}

MAKE_ARGS=	HOST=_FreeBSD NOOPT=TRUE PROGS="${ACPICA_TOOLS}"
MAKE_ARGS+=	CC="${CC}" LEX="${FLEX}" YACC="${YACC}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1001506
BUILD_DEPENDS+=	bison:${PORTSDIR}/devel/bison
BUILD_DEPENDS+=	gm4:${PORTSDIR}/devel/m4
MAKE_ARGS+=	MACROPROC="${LOCALBASE}/bin/gm4"
YACC=		${LOCALBASE}/bin/bison
.endif

do-install:
	${INSTALL_PROGRAM} ${ACPICA_TOOLS:S,^,${BUILD_WRKSRC}/bin/,} \
	    ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.post.mk>
