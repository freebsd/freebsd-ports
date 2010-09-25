# New ports collection makefile for:	superiotool
# Date created:		2009-09-30
# Whom:			Andriy Gapon <avg@icyb.net.ua>
#
# $FreeBSD$
#

PORTNAME=	superiotool
DISTVERSION=	20090930
CATEGORIES=	sysutils
MASTER_SITES=	http://www.icyb.net.ua/~avg/distfiles/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Helper tool for Super I/O chip detection and analysis

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_FILES=	sbin/superiotool
MAN8=		superiotool.8

WRKSRC=		${WRKDIR}/${PORTNAME}
SVNROOT=	svn://coreboot.org/repos/trunk/util/superiotool

gen-dist:
	@if [ ! -f ${LOCALBASE}/bin/svn ]; then \
		${ECHO_CMD} "ERROR: You need to have devel/subversion installed for gen-dist target"; \
		${FALSE}; \
	fi
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
		${MKDIR} ${WRKDIR}/svn; \
		cd ${WRKDIR}/svn && svn co ${SVNROOT}; \
		${TAR} cfj ${_DISTDIR}${DISTFILES} ${PORTNAME}; \
		cd ${WRKDIR} && ${RM} -rf svn; \
		cd ${.CURDIR} && ${MAKE} ${__softMAKEFLAGS} makesum; \
	fi

post-patch:
	@${REINPLACE_CMD} -e 's#/share/man/#/man/#g' -e 's#-ansi##g' \
		-Ee '\#^(CC|INSTALL|PREFIX)#s#=#?=#' \
		-e '\#^CFLAGS#s#=#+=#' -e 's#-O2##' \
		${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64: attempts to use i386 asm
.endif

.include <bsd.port.post.mk>
