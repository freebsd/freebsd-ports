# Created by: Stephane Legrand <stephane@lituus.fr>
# $FreeBSD$

PORTNAME=	bugs
PORTVERSION=	4.1.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	SUNSITE/apps/crypto
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Great cryptographic library and sample programs

LICENSE=	GPLv2

NO_STAGE=	yes
USES=		gmake
MAKE_ARGS=	CC="${CC}" BFLAG="${CFLAGS}" \
		INSTALL_PATH="${PREFIX}/${DISTNAME}"

PLIST_SUB=	PORTVERSION="${PORTVERSION}"

DOCSDIR=	${PREFIX}/${DISTNAME}/doc

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
# Sanitize permissions so "make clean" can work
	@${CHMOD} +x ${WRKSRC}/lib/unix ${WRKSRC}/lib/windows
# Allow parallel builds (-jX): fix make(1) syntax, register dependencies
	@${REINPLACE_CMD} -E 's+cd (.*); make+$$(MAKE) -C \1+' \
		${WRKSRC}/Makefile.bsd
	@${ECHO_CMD} 'apps: lib' >> ${WRKSRC}/Makefile.bsd
	@${REINPLACE_CMD} -E '/^(bcrypt|bchat|bpass|blogin|bkey|bpassdel|bmore|block|bunlock|shell):/s+ *$$+ extra.o+' \
		${WRKSRC}/apps/Makefile.bsd

post-configure:
	${MAKE_CMD} -C ${WRKSRC} bsd
	@${REINPLACE_CMD} -e 's/^install: instchoice all/install: instchoice/' ${WRKSRC}/Makefile;
	@${REINPLACE_CMD} -e 's+\(@echo "Copying docs.*\)+# \1+' ${WRKSRC}/Makefile;
	@${REINPLACE_CMD} -e 's+\(@cp -rf ./doc/.*\)+# \1+' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's+\(@cp -rf ./doc/.*\)+# \1+' ${WRKSRC}/Makefile

post-build:
	@${LN} -sf ${WRKSRC}/lib/unix/*.a ${WRKSRC}/lib/

post-install:
	@${MKDIR} ${PREFIX}/${DISTNAME}/include
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/${DISTNAME}/include
.for file in bchat bcrypt bhide bkey block blogin bmore bpass bpassdel bunlock
	@${STRIP_CMD} ${PREFIX}/${DISTNAME}/${file}
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR})
.endif

test: build
	${MAKE_CMD} -C ${WRKSRC} test

regression-test: test

.include <bsd.port.mk>
