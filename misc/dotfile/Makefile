# New ports collection makefile for: dotfile
# Date created:      11/12/96
# Whom:              oly@world.std.com
#
# $FreeBSD$
#

PORTNAME=	dotfile
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	misc tk
MASTER_SITES=	http://www.blackie.dk/dotfile/download/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	A GUI dotfile generator program to create .config files

BUILD_DEPENDS=	formail:${PORTSDIR}/mail/procmail

GNU_CONFIGURE=	yes
PLIST_SUB=	DISTNAME="${DISTNAME}"
NO_BUILD=	yes

MAN1=		dotfile.1

OPTIONS=	JAPANESE "Use Japanese as default language" off

USE_TK=		82
USE_TK_BUILD=	82

.include <bsd.port.pre.mk>

.if defined(WITH_JAPANESE)
CONFIGURE_ENV+=	LANGUAGE="japanese"
.endif

post-patch:
	@${RM} ${WRKSRC}/Modules/english/procmail/configure.orig
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

.include <bsd.port.post.mk>
