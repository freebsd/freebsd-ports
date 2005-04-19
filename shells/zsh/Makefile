# New ports collection makefile for:	zsh
# Date created:			11 Feb. 1995
# Whom:				torstenb
#
# $FreeBSD$
#

# The following compile-time options are available:
# NOSHARED=yes		compile a static version of zsh
#			(default: use dynamically loadable modules)
# WITHOUT_ZSH_MEM=yes	disable zsh-mem and zsh-secure-free options
#			(default: on)
# WITHOUT_ZSH_MAILDIR=yes disable support for Maildirs in MAIL and MAILPATH
#			(default: on)
# ZSH_ETCDIR=<dir>	directory for zsh system-wide configuration files:
#			zshenv, zlogin, zprofile, zshrc, zlogout.
#			e.g. use this to put config files inside ${PREFIX}
#			(default: /etc)
#			NOTE: does NOT have to be inside ${PREFIX} tree
# ZSH_FNDIR=<dir>	directory for zsh functions (part of distribution)
#			(default: ${PREFIX}/share/zsh/${ZSH_VER}/functions)
#			NOTE: should be inside ${PREFIX} tree
# ZSH_SITEFNDIR=<dir>	directory for zsh site functions (locally developed)
#			(default: ${PREFIX}/share/zsh/site-functions)
#			NOTE: does NOT have to be inside ${PREFIX} tree

PORTNAME=	zsh
PORTVERSION=	4.2.5
CATEGORIES=	shells
MASTER_SITES=	\
		http://archive.progeny.com/zsh/ \
		ftp://archive.progeny.com/zsh/ \
		http://www.zsh.org/pub/ \
		ftp://ftp.zsh.org/pub/ \
		ftp://sunsite.dk/pub/unix/shells/zsh/ \
		http://mirrors.dotsrc.org/zsh/ \
		ftp://mirrors.dotsrc.org/zsh/ \
		ftp://ftp.funet.fi/pub/unix/shells/zsh/ \
		ftp://nephtys.lip6.fr/pub/unix/shells/zsh/ \
		ftp://ftp.fu-berlin.de/pub/unix/shells/zsh/ \
		http://www.cs.elte.hu/pub/zsh/ \
		ftp://ftp.cs.elte.hu/pub/zsh/ \
		ftp://ftp.kfki.hu/pub/packages/zsh/ \
		ftp://ftp.math.technion.ac.il/pub/zsh/ \
		ftp://ftp.demon.nl/pub/mirrors/zsh/ \
		ftp://ftp.kappa.ro/pub/mirrors/ftp.zsh.org/pub/zsh/ \
		ftp://ftp.lysator.liu.se/pub/unix/zsh/ \
		ftp://sunsite.org.uk/package/zsh/ \
		ftp://ftp.rge.com/pub/shells/zsh/ \
		http://zsh.open-mirror.com/
DISTNAME=	${PORTNAME}-${ZSH_VER}
.if !defined(NOPORTDOCS)
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}-doc${EXTRACT_SUFX}
.endif

MAINTAINER?=	sergei@FreeBSD.org
COMMENT?=	The Z shell

ZSH_VER=	${PORTVERSION}
# Conflicts with shells/zsh-devel as it installs files into the same locations
CONFLICTS=	zsh-devel-[0-9]* zsh-4.1.*

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-curses-terminfo --with-tcsetpgrp \
		--enable-etcdir=${ZSH_ETCDIR} \
		--enable-fndir=${ZSH_FNDIR} --enable-function-subdirs \
		--enable-site-fndir=${ZSH_SITEFNDIR}

.if !defined(WITHOUT_ZSH_MEM)
CONFIGURE_ARGS+=	--enable-zsh-mem --enable-zsh-secure-free
.endif

.if !defined(WITHOUT_ZSH_MAILDIR)
CONFIGURE_ARGS+=	--enable-maildir-support
.endif

.if defined(NOSHARED)
CONFIGURE_ENV=		LDFLAGS="${LDFLAGS} -static"
CONFIGURE_ARGS+=	--disable-dynamic
PLIST_SUB+=		NO_STATIC="@comment "
.else
CONFIGURE_ARGS+=	--enable-dynamic
PLIST_SUB+=		NO_STATIC=""
.endif

# These variables can be overriden by user
ZSH_ETCDIR?=	/etc
ZSH_FNDIR?=	${DATADIR}/${ZSH_VER}/functions
ZSH_SITEFNDIR?=	${DATADIR}/site-functions

PLIST_SUB+=	ZSH_VER="${ZSH_VER}" ZSHETCDIR="${ZSH_ETCDIR}" \
		ZSH_FNDIR="${ZSH_FNDIR:S!${PREFIX}/!!}" \
		ZSH_SITEFNDIR="${ZSH_SITEFNDIR}"

MAN1=		zsh.1 zshbuiltins.1 zshcompctl.1 zshcompwid.1 zshcompsys.1 \
		zshcontrib.1 zshexpn.1 zshmisc.1 zshmodules.1 zshoptions.1 \
		zshparam.1 zshtcpsys.1 zshzftpsys.1 zshzle.1 zshall.1
DOCS=		LICENCE META-FAQ README Etc/BUGS Etc/CONTRIBUTORS Etc/FAQ \
		Etc/completion-style-guide \
		Doc/zsh*.html Doc/zsh.dvi Doc/zsh_a4.ps Doc/zsh_us.ps
EXAMPLES=	zlogin zshenv zshrc

post-patch:
	${REINPLACE_CMD} -e 's/link=dynamic/link=either/' ${WRKSRC}/Src/Modules/*.mdd

post-build:
	# Fix ".so" macro problem by using "soelim" command.
	${LN} -sf ${WRKSRC}/Doc ${WRKSRC}/man1
	${MV} ${WRKSRC}/Doc/zshall.1 ${WRKSRC}/Doc/zshall.1.source
	cd ${WRKSRC} && /usr/bin/soelim ${WRKSRC}/Doc/zshall.1.source > \
		${WRKSRC}/Doc/zshall.1

.if !defined(NOPORTDOCS)
INFO=	zsh

pre-install:
	@${MKDIR} ${PREFIX}/info
	makeinfo --no-split --output=${PREFIX}/info/zsh.info \
		${WRKSRC}/Doc/zsh.texi
	install-info ${PREFIX}/info/zsh.info ${PREFIX}/info/dir
.endif

post-install:
	${LN} ${PREFIX}/bin/zsh ${PREFIX}/bin/rzsh
	${TEST} -d ${ZSH_ETCDIR} || ${MKDIR} ${ZSH_ETCDIR}
	${TEST} -d ${ZSH_SITEFNDIR} || ${MKDIR} ${ZSH_SITEFNDIR}
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/StartupFiles && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif
	@${ECHO_MSG} "Updating /etc/shells"
	@${CP} /etc/shells /etc/shells.bak
	@(${GREP} -v ${PREFIX}/bin/zsh /etc/shells.bak \
	  | ${GREP} -v ${PREFIX}/bin/rzsh; \
	  ${ECHO_CMD} ${PREFIX}/bin/zsh; \
	  ${ECHO_CMD} ${PREFIX}/bin/rzsh) > /etc/shells
	@${RM} /etc/shells.bak

.include <bsd.port.mk>
