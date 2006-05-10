# New ports collection makefile for: dotfile
# Date created:      11/12/96
# Whom:              oly@world.std.com
#
# $FreeBSD$
#

PORTNAME=	dotfile
PORTVERSION=	2.4.1
CATEGORIES=	misc tk82
MASTER_SITES=	http://www.blackie.dk/dotfile/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GUI dotfile generator program to create .config files

BUILD_DEPENDS=	formail:${PORTSDIR}/mail/procmail
LIB_DEPENDS=	tk82.1:${PORTSDIR}/x11-toolkits/tk82
RUN_DEPENDS=	wish8.2:${PORTSDIR}/x11-toolkits/tk82
.if defined(WITH_JAPANESE)
BUILD_DEPENDS+=	wish8.0jp:${PORTSDIR}/japanese/tk80
RUN_DEPENDS+=	wish8.0jp:${PORTSDIR}/japanese/tk80
.endif

GNU_CONFIGURE=	yes
PLIST_SUB=	DISTNAME="${DISTNAME}"
NO_BUILD=	yes

.if !defined(BATCH)
IS_INTERACTIVE=	yes
.endif

MAN1=		dotfile.1

post-patch:
.if defined(BATCH)
.if defined(WITH_JAPANESE)
	@${REINPLACE_CMD} -e "s|set answer \"\"|set answer \"2\"|" \
		${WRKSRC}/language.tcl
.else
	@${REINPLACE_CMD} -e "s|set answer \"\"|set answer \"1\"|" \
		${WRKSRC}/language.tcl
.endif # WITH_JAPANESE
.endif # BATCH
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/dotfile

post-configure:
	@(cd ${WRKSRC}/Modules/english/procmail && CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/dotfile
	@${MKDIR} ${DOCSDIR}/procmail
	@${MKDIR} ${DOCSDIR}/tcsh
	@${INSTALL_DATA} ${WRKSRC}/Doc/index.html ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/Doc/dotfile/* ${DOCSDIR}/dotfile
	@${INSTALL_DATA} ${WRKSRC}/Doc/tcsh/* ${DOCSDIR}/tcsh
	@${INSTALL_DATA} ${WRKSRC}/Doc/procmail/* ${DOCSDIR}/procmail
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Documentation is installed in ${DOCSDIR}"
	@${ECHO_CMD} ""
.endif

.include <bsd.port.mk>
