# New ports collection makefile for:	zsh
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $FreeBSD$
#

PORTNAME=	zsh
PORTVERSION=	4.0.6
CATEGORIES=	shells
MASTER_SITES=	ftp://ftp.zsh.org/%SUBDIR%/ \
		ftp://ftp.sterling.com/%SUBDIR%/ \
		ftp://ftp.rge.com/pub/shells/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/%SUBDIR%/ \
		ftp://ftp.ips.oz.au/pub/packages/%SUBDIR%/ \
		ftp://ftp.uit.no/pub/unix/shells/%SUBDIR%/ \
		ftp://ftp.iij.ad.jp/pub/misc/%SUBDIR%/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/utils/shell/%SUBDIR%/ \
		ftp://ftp.icm.edu.pl/vol/wojsyl/%SUBDIR%/ \
		ftp://ftp.sunsite.auc.dk/disk1/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} zsh-${PORTVERSION}-doc${EXTRACT_SUFX}
.endif

MAINTAINER=	will@FreeBSD.org

USE_BZIP2=	yes
USE_REINPLACE=	yes

ZSH_VER=	${PORTVERSION}
ZSHFUNC_SUBDIR=	share/zsh/${ZSH_VER}/functions
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-zsh-mem --enable-zsh-secure-free --enable-dynamic \
		--enable-maildir-support --with-curses-terminfo

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install.html
.endif

MAN1=		zsh.1 zshbuiltins.1 zshcompctl.1 zshcompwid.1 zshcompsys.1 \
		zshcontrib.1 zshexpn.1 zshmisc.1 zshmodules.1 zshoptions.1 \
		zshparam.1 zshzftpsys.1 zshzle.1 zshall.1

PLIST_SUB=	ZSH_VER="${ZSH_VER}" ZSHFUNC_SUBDIR="${ZSHFUNC_SUBDIR}"

.if defined(WANT_STATIC)
CONFIGURE_ENV+=	"LDFLAGS=-static"
PLIST_SUB+=	NO_STATIC="@comment "
.else
PLIST_SUB+=	NO_STATIC=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\$$(htmldir)|\$$(prefix)/share/doc/zsh|' \
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
.if !defined(NOPORTDOCS)
	@${INSTALL_DATA} ${WRKSRC}/Doc/zsh.info* ${PREFIX}/info
.endif
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
