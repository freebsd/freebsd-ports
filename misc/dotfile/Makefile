# New ports collection makefile for: dotfile
# Version required:  2.0
# Date created:      11/12/96
# Whom:              oly@world.std.com
#
# $Id: Makefile,v 1.7 1998/02/23 04:09:58 steve Exp $
#

DISTNAME=	dotfile-2.2
CATEGORIES=	misc tk80
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	oly@world.std.com

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80
RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11/tk80

BROKEN=		package

GNU_CONFIGURE=	yes
MAN1=		dotfile.1

NO_BUILD=	yes

pre-fetch:
.if !defined(PROCMAIL)
	@${ECHO_MSG} "This port requires an extra configure if you intend to use it to create procmailrc files.  If you'd like this capability restart with \"make PROCMAIL=yes\"."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you choose not to compile in this capability now, you can add it later by running configure in ${PREFIX}/${DISTNAME}/procmail."
.endif

post-configure:
.if defined(PROCMAIL)
	@(cd ${WRKSRC}/Modules/procmail && CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
.endif

post-install:
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}/dotfile
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}/procmail
	@${MKDIR} ${PREFIX}/share/doc/${DISTNAME}/tcsh
	${INSTALL_DATA} ${WRKSRC}/Doc/index.html ${PREFIX}/share/doc/${DISTNAME}
	${INSTALL_DATA} ${WRKSRC}/Doc/dotfile/* ${PREFIX}/share/doc/${DISTNAME}/dotfile
	${INSTALL_DATA} ${WRKSRC}/Doc/tcsh/* ${PREFIX}/share/doc/${DISTNAME}/tcsh
	${INSTALL_DATA} ${WRKSRC}/Doc/procmail/* ${PREFIX}/share/doc/${DISTNAME}/procmail
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
