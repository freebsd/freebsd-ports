# New ports collection makefile for:	LPRngTool
# Date created:		10 Oct 2001
# Whom:			papowell@lprng.com
#
# $FreeBSD$
#

PORTNAME=	LPRngTool
PORTVERSION=	1.3.2
CATEGORIES=	 sysutils print
MASTER_SITES=	ftp://ftp.lprng.com/pub/%SUBDIR%/ \
		ftp://ftp.cise.ufl.edu/pub/mirrors/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/%SUBDIR%/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/os/unix/utils/%SUBDIR%/ \
		ftp://ftp.uni-paderborn.de/pub/unix/printer/%SUBDIR%/
MASTER_SITE_SUBDIR=	LPRng/LPRngTool
EXTRACT_SUFX=	.tgz

MAINTAINER=	papowell@astart.com

BUILD_DEPENDS=	\
	gs:${PORTSDIR}/print/ghostscript-afpl \
	wish8.3:${PORTSDIR}/x11-toolkits/tk83 \
	a2ps:${PORTSDIR}/print/a2ps-letter

#RUN_DEPENDS=	ifhp:${PORTSDIR}/print/ifhp

.if defined(PREFIX)
  CONFIGURE_ARGS+=  --prefix="${PREFIX}"
.endif
.if defined(SYSCONFDIR)
  CONFIGURE_ARGS+=  --with-sysconfdir="${SYSCONFDIR}"
.endif

HAS_CONFIGURE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

HAS_CONFIGURE=	yes

CONFIGURE_ARGS+=\
    --with-spool_directory=/var/spool/lpd

MAN1=lprngtool.1

pre-everything::
	@${ECHO_MSG} "If you want to replace the default printing system with LPRng, use:"
	@${ECHO_MSG} "  make PREFIX=/usr SYSCONFDIR=/etc clean all install"
	@if [ "${PREFIX}" = "/usr" -a ! -d /usr/man ] ; then \
		${ECHO_MSG} "The man pages will be installed in /usr/man." ; \
		${ECHO_MSG} "You should make a symbolic link /usr/share/man from /usr/man"; \
		${ECHO_MSG} "   ln -s /usr/share/man /usr/man"; \
		${ECHO_MSG} "If you do not, you will retain the old FreeBSD man pages."; \
		${ECHO_MSG} "See the hier(7) man page for details of the FreeBSD file system"; \
		${ECHO_MSG} "layout.  Configure is not equipped to determine the location of"; \
		${ECHO_MSG} 'man pages and defaults to $${PREFIX}/man, which is incorrect for FreeBSD.'; \
		exit 1; \
	fi
	@${ECHO_MSG} "Configuring with '${CONFIGURE_ARGS}'"

.include <bsd.port.mk>
