# Ports collection makefile for:	ifhp
# Date created:		10 Oct 2001
# Whom:			papowell@astart.com
#
# $FreeBSD$
#

PORTNAME=	ifhp
PORTVERSION=	3.5.7
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lprng.com/pub/%SUBDIR%/ \
		ftp://ftp.cise.ufl.edu/pub/mirrors/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/%SUBDIR%/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/os/unix/utils/%SUBDIR%/ \
		ftp://ftp.uni-paderborn.de/pub/unix/printer/%SUBDIR%/
MASTER_SITE_SUBDIR=	LPRng/ifhp
EXTRACT_SUFX=	.tgz

MAINTAINER=	papowell@astart.com
COMMENT=	IFHP - A highly configurable print filter for LPRng

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS= \
	--with-ldopts="-L${LOCALBASE}/lib" \
	--with-ccopts="-I${LOCALBASE}/include"
.if defined(PREFIX)
CONFIGURE_ARGS+=	--prefix="${PREFIX}"
.endif
.if defined(SYSCONFDIR)
CONFIGURE_ARGS+=	--sysconfdir="${SYSCONFDIR}"
.endif

MAN8=	ifhp.8 textps.8

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
	fi
	@${ECHO_MSG} "Configuring with '${CONFIGURE_ARGS}'"

post-install:
.if !defined(NOPORTDOCS)
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0555 ${DOCSDIR}
.for ext in html pdf ppt ps txt gif jpg png
	@for i in `${LS} ${WRKSRC}/HOWTO |${GREP} "\.${ext}$$"`; \
		do ${INSTALL_DATA} ${WRKSRC}/HOWTO/$$i ${DOCSDIR}; done
.endfor
.endif
	@${SED} -e "s!DOCSDIR!${DOCSDIR}/!" ${PKGMESSAGE}

.include <bsd.port.mk>
