# New ports collection makefile for:	zsh-devel
# Date created:			31 October 1998
# Whom:				shige
#
# $FreeBSD$
#

PORTNAME=	zsh
PORTVERSION=	${ZSH_VER}.dev${ZSH_DEV_REV}
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.zsh.org/%SUBDIR%/ \
		ftp://ftp.sterling.com/%SUBDIR%/ \
		ftp://ftp.rge.com/pub/shells/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/%SUBDIR%/ \
		ftp://ftp.ips.oz.au/pub/packages/%SUBDIR%/ \
		ftp://ftp.uit.no/pub/unix/shells/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}/development

DISTNAME=	${PORTNAME}-${ZSH_VER}-dev-${ZSH_DEV_REV}

MAINTAINER=	shige@FreeBSD.org

USE_AUTOCONF=   yes
USE_REINPLACE=	yes

ZSH_VER=	4.1.0
ZSH_DEV_REV=	5
ZSHFUNC_SUBDIR=	share/zsh/${ZSH_VER}-dev-${ZSH_DEV_REV}/functions
NO_LATEST_LINK=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --enable-zsh-mem --enable-zsh-secure-free --enable-dynamic \
		--enable-maildir-support

.if !defined(NOPORTDOCS)
INSTALL_TARGET= install install.info
.endif

MAN1=		zsh.1 zshbuiltins.1 zshcompctl.1 zshexpn.1 zshmisc.1 \
		zshoptions.1 zshall.1 zshparam.1 zshzle.1 zshmodules.1 \
		zshzftpsys.1 zshcompsys.1 zshcompwid.1

PLIST_SUB=	ZSH_VER="${ZSH_VER}-dev-${ZSH_DEV_REV}" \
		ZSHFUNC_SUBDIR="${ZSHFUNC_SUBDIR}"

.if defined(WANT_STATIC)
CONFIGURE_ENV+=	"LDFLAGS=-static"
PLIST_SUB+=	NO_STATIC="@comment "
.else
PLIST_SUB+=	NO_STATIC=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's!\$\(htmldir\)!\$\(prefix\)/share/doc/zsh!' \
		${WRKSRC}/Doc/Makefile.in

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
	@${MKDIR} ${PREFIX}/share/examples/zsh
.for file in zlogin zshenv zshrc
	${INSTALL_DATA} ${WRKSRC}/StartupFiles/${file} \
		${PREFIX}/share/examples/zsh
.endfor
	@install-info ${PREFIX}/info/zsh.info ${PREFIX}/info/dir
	@${ECHO} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak; \
		${ECHO_CMD} ${PREFIX}/bin/zsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
