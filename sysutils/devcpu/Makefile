# New ports collection makefile for:	devcpu
# Date created:		2006-08-16
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	devcpu
PORTVERSION=	0.8.3
PORTREVISION=	0
CATEGORIES=	sysutils kld
MASTER_SITES=	ftp://ftp.SpringDaemons.com/soft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kernel module that provides access to i386 MSRs and cpuid info

RUN_DEPENDS=	${STAMPFILE}:${PORTSDIR}/sysutils/devcpu-data

USE_BZIP2=	yes
USE_RC_SUBR=	devcpu
USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

ONLY_FOR_ARCHS=	i386 amd64
NO_PACKAGE=	depends on kernel

PLIST_SUB=	KMODDIR="${KMODDIR:C,^/,,}"
KMODDIR=	/boot/modules
MAKE_ENV+=	KMODDIR="${KMODDIR}" BINDIR="${PREFIX}/bin"

STAMPFILE=	${LOCALBASE}/share/${PORTNAME}/.do_not_delete

OPTIONS=	EXTRACTOR "Install Award Bios microcode extracting utility" off 

MAN4=		cpu.4
MAN8=		cpu_microcode_tool.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601000
IGNORE=		not supported
.endif

.if ${OSVERSION} >= 701102
IGNORE=		already included into base system
.endif

.if defined(WITH_EXTRACTOR)
RUN_DEPENDS+=	${RUBY_SITEARCHLIBDIR}/mmap.so:${PORTSDIR}/devel/ruby-mmap \
		${RUBY_SITEARCHLIBDIR}/lhalib.so:${PORTSDIR}/archivers/ruby-lha
PLIST_SUB+=	EXTRACTOR=""
.else
PLIST_SUB+=	EXTRACTOR="@comment "
.endif

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

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.if defined(WITH_EXTRACTOR)
	${INSTALL_SCRIPT} ${WRKSRC}/tools/extract_mcodes.rb ${PREFIX}/libexec/
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
