# New ports collection makefile for: dotfile
# Date created:      11/12/96
# Whom:              oly@world.std.com
#
# $FreeBSD$
#

PORTNAME=	dotfile
PORTVERSION=	2.2
CATEGORIES=	misc tk82
MASTER_SITES=	ftp://ftp.imada.ou.dk/pub/dotfile/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82

GNU_CONFIGURE=	yes
MAN1=		dotfile.1

NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dotfile

post-configure:
	@(cd ${WRKSRC}/Modules/procmail && CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

.if !defined(DISPLAY)
PLIST=		${WRKDIR}/PLIST
pre-install:
	@${CAT} ${PKGDIR}/pkg-plist | ${SED} -e '/fvwm.\/bytecompile/d' > ${PLIST}
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
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
