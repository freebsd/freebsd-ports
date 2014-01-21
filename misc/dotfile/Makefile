# Created by: oly@world.std.com
# $FreeBSD$

PORTNAME=	dotfile
PORTVERSION=	2.4.1
PORTREVISION=	2
CATEGORIES=	misc tk
MASTER_SITES=	http://www.blackie.dk/dotfile/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI dotfile generator program to create .config files

BUILD_DEPENDS=	formail:${PORTSDIR}/mail/procmail

GNU_CONFIGURE=	yes
PLIST_SUB=	DISTNAME="${DISTNAME}"
NO_BUILD=	yes
USES=		tk

MAN1=		dotfile.1

OPTIONS_DEFINE=	JAPANESE
JAPANESE_DESC=	Use Japanese as default language

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MJAPANESE}
CONFIGURE_ENV+=	LANGUAGE="japanese"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g; s|%%WISH%%|wish${TK_VER}|g; \
		s|%%TCLSH%%|tclsh${TCL_VER}|g" ${WRKSRC}/${CONFIGURE_SCRIPT} \
		${WRKSRC}/Generator/makeHelp ${WRKSRC}/Modules/english/procmail/${CONFIGURE_SCRIPT}
	${FIND} ${WRKSRC} \( -name "*.orig" -o -name "*.bak" \) -delete

post-configure:
	@(cd ${WRKSRC}/Modules/english/procmail && CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	INSTALL="${INSTALL} -c -o ${BINOWN} -g ${BINGRP}" \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

do-install:
	cd ${WRKSRC} && ${SETENV} LC_ALL=C ${MAKE} install

post-install:
.if ${PORT_OPTIONS:MDOCS}
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
