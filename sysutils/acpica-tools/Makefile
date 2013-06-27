# $FreeBSD$

PORTNAME=	acpica
PORTVERSION=	20130626
CATEGORIES=	sysutils devel
MASTER_SITES=	https://acpica.org/sites/acpica/files/ \
		LOCAL
MASTER_SITE_SUBDIR=	jkim
PKGNAMESUFFIX=	-tools
DISTNAME=	${PORTNAME}-unix2-${PORTVERSION}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Tools from the ACPI Component Architecture (ACPICA) project

LICENSE=	BSD

USE_GMAKE=	yes
MAKE_ARGS=	HOST=_FreeBSD
WRKSRC_SUBDIR=	generate/unix
LFLAGS=		-i -s
YFLAGS=		-v -d
.if !empty(YACC:M*bison*)
YFLAGS+=	-y
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CC[[:blank:]]*=.*|CC = ${CC}|' \
	    -e 's|INSTALLPROG = install -D|INSTALLPROG = ${INSTALL_PROGRAM}|' \
	    -e 's|^LEX[[:blank:]]*=.*|LEX = ${FLEX}|' \
	    -e 's|^LFLAGS[[:blank:]]*+=.*|LFLAGS = ${LFLAGS}|' \
	    -e 's|^YACC[[:blank:]]*=.*|YACC = ${YACC}|' \
	    -e 's|^YFLAGS[[:blank:]]*+=.*|YFLAGS = ${YFLAGS}|' \
	    ${WRKSRC}/Makefile.config

.include <bsd.port.mk>
