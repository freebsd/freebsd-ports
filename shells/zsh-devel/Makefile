# New ports collection makefile for:	zsh-devel
# Date created:			31 October 1998
# Whom:				shige
#
# $FreeBSD$
#

PORTNAME=	zsh
PORTVERSION= 	${ZSH_VER}
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.zsh.org/zsh/ \
		ftp://ftp.sterling.com/zsh/ \
		ftp://ftp.rge.com/pub/zsh/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/zsh/ \
		ftp://ftp.ips.oz.au/pub/packages/zsh/ \
		ftp://ftp.uit.no/pub/unix/shells/zsh/ \
		http://people.FreeBSD.org/~knu/ports/distfiles/

DISTFILES=	zsh-${ZSH_VER}.tar.gz ${ZSHFUNC_FILES}

MAINTAINER=	shige@FreeBSD.org

EXTRACT_ONLY=	zsh-${ZSH_VER}.tar.gz
ZSHFUNC_FILES=	zsh-functions-freebsd-2000.03.31.tar.gz
ZSHFUNC_SUBDIR=	share/zsh/functions
NO_LATEST_LINK=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-zsh-mem --enable-zsh-secure-free --enable-dynamic
MAN1=		zsh.1 zshbuiltins.1 zshcompctl.1 zshexpn.1 zshmisc.1 \
		zshoptions.1 zshall.1 zshparam.1 zshzle.1 zshmodules.1 \
		zshzftpsys.1 zshcompsys.1 zshcompwid.1

ZSH_VER=	3.1.6
PLIST_SUB=	ZSH_VER=${ZSH_VER} ZSHFUNC_SUBDIR=${ZSHFUNC_SUBDIR}

# If you want to build a static binary, uncomment the following line
#LDFLAGS+=-static

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

post-install:
	@for i in ${ZSHFUNC_FILES} ; do \
		${TAR} zxf ${DISTDIR}/$${i} -C ${PREFIX}/${ZSHFUNC_SUBDIR} ;\
	done
	@${INSTALL_DATA} ${WRKSRC}/Doc/zsh.info ${PREFIX}/info
	@install-info ${PREFIX}/info/zsh.info ${PREFIX}/info/dir
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; \
	  ${ECHO} ${PREFIX}/bin/zsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
