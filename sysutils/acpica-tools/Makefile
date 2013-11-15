# $FreeBSD$

PORTNAME=	acpica
PORTVERSION=	20131115
CATEGORIES=	sysutils devel
MASTER_SITES=	https://acpica.org/sites/acpica/files/ \
		LOCAL
MASTER_SITE_SUBDIR=	jkim
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTNAME}-unix2-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Tools from the ACPI Component Architecture (ACPICA) project

LICENSE=	BSD

MAKE_ARGS=	HOST=_FreeBSD INSTALLFLAGS="${INSTALL_PROGRAM:S/^${INSTALL}//}"
MAKE_ARGS+=	NOOPT=TRUE

USES=		gmake
WRKSRC_SUBDIR=	generate/unix
LFLAGS=		-i -s

# XXX 20130927 broke support for yacc.
USES+=		bison
YACC=		bison
YFLAGS=		-y

post-patch:
	@${REINPLACE_CMD} -e 's|^CC[[:blank:]]*=.*|CC = ${CC}|' \
	    -e 's|^INSTALL[[:blank:]]*=.*|INSTALL = ${INSTALL}|g' \
	    -e 's|^LEX[[:blank:]]*=.*|LEX = ${FLEX}|' \
	    -e 's|^LFLAGS[[:blank:]]*\+=.*|LFLAGS = ${LFLAGS}|' \
	    -e 's|^YACC[[:blank:]]*=.*|YACC = ${YACC}|' \
	    -e 's|^YFLAGS[[:blank:]]*\+=.*|YFLAGS = ${YFLAGS}|' \
	    ${WRKSRC}/Makefile.config

.include <bsd.port.mk>
