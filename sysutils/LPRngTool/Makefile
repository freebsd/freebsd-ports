# New ports collection makefile for:	LPRngTool
# Date created:		10 Oct 2001
# Whom:			papowell@lprng.com
#
# $FreeBSD$
#

PORTNAME=	LPRngTool
PORTVERSION=	1.3.2
PORTREVISION=	3
CATEGORIES=	 sysutils print
MASTER_SITES=	ftp://ftp.lprng.com/pub/%SUBDIR%/ \
		ftp://ftp.cise.ufl.edu/pub/mirrors/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/%SUBDIR%/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/os/unix/utils/%SUBDIR%/ \
		ftp://ftp.uni-paderborn.de/pub/unix/printer/%SUBDIR%/
MASTER_SITE_SUBDIR=	LPRng/LPRngTool
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configuration Tool for LPRng

BUILD_DEPENDS=	a2ps:${PORTSDIR}/print/a2ps-letter \
		wish:${PORTSDIR}/x11-toolkits/tk-wrapper

#RUN_DEPENDS=	ifhp:${PORTSDIR}/print/ifhp

USE_GHOSTSCRIPT_BUILD=	yes
USE_TK_BUILD=	yes

.if defined(SYSCONFDIR)
PLIST_SUB+=	CWD="" SYSCONFDIR="${SYSCONFDIR:S,^/,,}"
.else
SYSCONFDIR=	${PREFIX}/etc
PLIST_SUB+=	CWD="@comment " SYSCONFDIR="${SYSCONFDIR:S,^${PREFIX}/,,}"
.endif

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--with-spool_directory=/var/spool/lpd \
			--with-sysconfdir="${SYSCONFDIR}"

MAN1=		lprngtool.1

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

post-install:
	@if [ ! -f ${SYSCONFDIR}/lprngtool.conf ]; then \
		${CP} ${SYSCONFDIR}/lprngtool.conf.sample ${SYSCONFDIR}/lprngtool.conf; \
	fi

.include <bsd.port.mk>
