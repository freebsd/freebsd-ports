# New ports collection makefile for:	zsh-devel
# Date created:			31 October 1998
# Whom:				shige
#
# $FreeBSD$
#

PORTNAME=	zsh
PORTVERSION=	3.1.9
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.zsh.org/%SUBDIR%/ \
		ftp://ftp.sterling.com/%SUBDIR%/ \
		ftp://ftp.rge.com/pub/shells/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/%SUBDIR%/ \
		ftp://ftp.ips.oz.au/pub/packages/%SUBDIR%/ \
		ftp://ftp.uit.no/pub/unix/shells/%SUBDIR%/
# last one for ${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	${PORTNAME} knu
DISTNAME=	${PORTNAME}-${ZSH_VER}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${ZSHFUNC_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	shige@FreeBSD.org

USE_AUTOCONF=	yes

ZSH_VER=	${PORTVERSION}
ZSHFUNC_FILES=	zsh-functions-freebsd-2000.09.06.tar.gz
ZSHFUNC_SUBDIR=	share/zsh/${ZSH_VER}/functions
NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-zsh-mem --enable-zsh-secure-free --enable-dynamic
INSTALL_TARGET=	install install.info
MAN1=		zsh.1 zshbuiltins.1 zshcompctl.1 zshexpn.1 zshmisc.1 \
		zshoptions.1 zshall.1 zshparam.1 zshzle.1 zshmodules.1 \
		zshzftpsys.1 zshcompsys.1 zshcompwid.1
PLIST_SUB=	ZSH_VER="${ZSH_VER}" ZSHFUNC_SUBDIR="${ZSHFUNC_SUBDIR}"

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

post-extract:
	@${MKDIR} ${WRKDIR}/functions
	@for i in ${ZSHFUNC_FILES} ; do \
		${TAR} zxf ${DISTDIR}/$${i} -C ${WRKDIR}/functions ;\
	done

post-build:
# Fix ".so" macro problem by using "soelim" command.
	@(cd ${WRKSRC} ; \
		${LN} -sf ./Doc man1 ; \
		if [ ! -f ./man1/zshall.1.source ]; then \
			${MV} -f ./man1/zshall.1 ./man1/zshall.1.source ; \
		fi ; \
		${RM} -f ./man1/zshall.1 ; \
		/usr/bin/soelim ./man1/zshall.1.source > ./man1/zshall.1 ; \
	)
	@cd ${WRKSRC}/Doc && ${MAKE} info

post-install:
	@${INSTALL_DATA} ${WRKDIR}/functions/* ${PREFIX}/${ZSHFUNC_SUBDIR}
	@${INSTALL_DATA} ${WRKSRC}/Doc/zsh.info ${PREFIX}/info
	@install-info ${PREFIX}/info/zsh.info ${PREFIX}/info/dir
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; \
	  ${ECHO} ${PREFIX}/bin/zsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
