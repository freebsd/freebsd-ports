# New ports collection makefile for:	zsh
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $FreeBSD$
#

PORTNAME=	zsh
PORTVERSION=	4.0.1
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.zsh.org/%SUBDIR%/ \
		ftp://ftp.sterling.com/%SUBDIR%/ \
		ftp://ftp.rge.com/pub/shells/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/%SUBDIR%/ \
		ftp://ftp.ips.oz.au/pub/packages/%SUBDIR%/ \
		ftp://ftp.uit.no/pub/unix/shells/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	will@FreeBSD.org

USE_AUTOCONF=	yes

ZSH_VER=	${PORTVERSION}
ZSHFUNC_SUBDIR=	share/zsh/${ZSH_VER}/functions
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-zsh-mem --enable-zsh-secure-free --enable-dynamic \
		--enable-maildir-support
INSTALL_TARGET=	install install.info
MAN1=		zsh.1 zshbuiltins.1 zshcompctl.1 zshcompwid.1 zshcompsys.1 \
		zshcontrib.1 zshexpn.1 zshmisc.1 zshmodules.1 zshoptions.1 \
		zshparam.1 zshzftpsys.1 zshzle.1 zshall.1
PLIST_SUB=	ZSH_VER="${ZSH_VER}" ZSHFUNC_SUBDIR="${ZSHFUNC_SUBDIR}"

.if defined(WANT_STATIC)
CONFIGURE_ENV+= "LDFLAGS=-static"
PLIST_SUB+=	NO_STATIC="@comment "
.else
PLIST_SUB+=	NO_STATIC=""
.endif

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

pre-install:
	@${RM} -f ${WRKSRC}/Completion/Unix/Command/_mount.orig

post-install:
	@${INSTALL_DATA} ${WRKSRC}/Doc/zsh.info ${PREFIX}/info
	@install-info ${PREFIX}/info/zsh.info ${PREFIX}/info/dir
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; \
	  ${ECHO} ${PREFIX}/bin/zsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
