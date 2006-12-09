# New ports collection makefile for:	devcpu
# Date created:		2006-08-16
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	devcpu
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://mbsd.msk.ru/dist/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Kernel module that provides access to i386 MSRs and cpuid info

USE_BZIP2=	yes

ONLY_FOR_ARCHS=	i386 amd64
NO_PACKAGE=	depends on kernel

PLIST_SUB=	KMODDIR="${KMODDIR:C,^/,,}"

MAN4=		cpu.4
MAN8=		cpu_microcode_tool.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
IGNORE=		not supported
.endif

MAKE_ENV+=	KMODDIR="${KMODDIR}" \
		BINDIR="${PREFIX}/bin"

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source to be installed
.endif

post-patch:
	${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" \
		${WRKSRC}/cpu_microcode_tool/cpu_microcode_tool.8

post-install:
	${INSTALL_DATA} ${WRKSRC}/cpu/cpu.h ${PREFIX}/include/
	${INSTALL_MAN} ${WRKSRC}/cpu/cpu.4 ${PREFIX}/man/man4/
	${INSTALL_MAN} ${WRKSRC}/cpu_microcode_tool/cpu_microcode_tool.8 \
		 ${PREFIX}/man/man8/

	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/mcodes/* ${DATADIR}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
