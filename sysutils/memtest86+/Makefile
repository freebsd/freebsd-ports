# New ports collection makefile for:	memtest86+
# Date created:				2009-03-10
# Whom:					Andriy Gapon <avg@icyb.net.ua>
#
# $FreeBSD$
#

PORTNAME=	memtest86+
PORTVERSION=	4.00
CATEGORIES=	sysutils
MASTER_SITES=	http://www.memtest.org/download/${PORTVERSION}/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Stand-alone memory test for x86 architecture computers

ONLY_FOR_ARCHS=	i386 amd64

USE_DOS2UNIX=	README memtest.lds setup.S
USE_GMAKE=	yes
ALL_TARGET=	all
PORTDOCS=	*

# Please provide absolute path below (cannot be root)
BOOT_DIR?=	/boot/opt

OPTIONS=	ISO	"Build bootable ISO image"			off \
		BOOT	"Build ELF image loadable by boot2 and loader"	on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ISO) && defined(WITHOUT_BOOT)
IGNORE=		cannot be built: neither ISO nor BOOT selected
.endif

.if defined(WITH_BOOT)
SUB_FILES=	pkg-message
SUB_LIST+=	BOOT_DIR=${BOOT_DIR}
.endif

.if defined(WITH_ISO)
USE_CDRTOOLS=	yes
ALL_TARGET+=	iso
.endif

pre-fetch:
.if !defined(PACKAGE_BUILDING)
	@${ECHO} "If you only need bootable ISO image of memtest86+, you can"
	@${ECHO} "simply download it from http://www.memtest.org/.  Use this"
	@${ECHO} "port if you need ELF image of memtest86+ that can be loaded"
	@${ECHO} "by boot2 or loader(8), or if you want to use this port to"
	@${ECHO} "build ISO image with custom tweaks in memtest86+ code."
.endif

PLIST=		${WRKDIR}/pkg-plist

pre-install:
# Generate PLIST dynamically because install things outside normal ${PREFIX}
	@${TEST} -f ${PLIST} && ${RM} ${PLIST} || ${TRUE}
.if defined(WITH_ISO)
	@${ECHO} "%%DATADIR%%/mt${PORTVERSION:C/\.//}.iso" >> ${PLIST}
	@${ECHO} "@dirrm %%DATADIR%%" >> ${PLIST}
.endif
.if defined(WITH_BOOT)
	@${ECHO} "@cwd ${BOOT_DIR:H}" >> ${PLIST}
	@${ECHO} "${BOOT_DIR:T}/memtest86+" >> ${PLIST}
	@${ECHO} "@dirrm ${BOOT_DIR:T}" >> ${PLIST}
.endif

do-install:
.if defined(WITH_ISO)
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mt${PORTVERSION:C/\.//}.iso ${DATADIR}
.endif
.if defined(WITH_BOOT)
	@${MKDIR} ${BOOT_DIR}
# XXX is INSTALL_KLD really appropriate here? XXX
	${INSTALL_KLD} ${WRKSRC}/memtest ${BOOT_DIR}/memtest86+
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
.if defined(WITH_BOOT)
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
